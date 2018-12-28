#include "TStack.h"
#include <memory>

template <class T>
TStack<T>::TStack() {
	head = nullptr;
}

template <class T> void TStack<T>::Push(T *item) {
	std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item));
	other->SetNext(head);
	head = other;

}



/*
TStack::TStack(const TStack& orig) {
	head = orig.head;
}
*/
template <class T> void TStack<T>::sort() {
	if (size() > 1) {
		std::shared_ptr<T> middle = Pop();
		TStack<T> left, right;

		while (!Empty()) {
			std::shared_ptr<T> item = Pop();
			if (*item < *middle) {
				left.Push(item);
			}
			else {
				right.Push(item);
			}
		}

		left.sort();
		right.sort();

		while (!left.Empty()) Push(left.Pop_last());
		Push(middle);
		while (!right.Empty()) Push(right.Pop_last());

	}
}

template<class T > std::future<void> TStack<T>::sort_in_background() {
	std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TStack<T>::sort_parallel), this));
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));
	th.detach();
	return res;
}

template <class T> std::shared_ptr<T> TStack<T>::Pop_last() {
	std::shared_ptr<T> result;

	if (head != nullptr) {
		std::shared_ptr<TStackItem < T>> element = head;
		std::shared_ptr<TStackItem < T>> prev = nullptr;

		while (element->GetNext() != nullptr) {
			prev = element;
			element = element->GetNext();
		}

		if (prev != nullptr) {
			prev->SetNext(nullptr);
			result = element->GetValue();

		}
		else {
			result = element->GetValue();
			head = nullptr;
		}
	}

	return result;

}


template <class T> void TStack<T>::sort_parallel() {
	if (size() > 1) {
		std::shared_ptr<T> middle = Pop_last();
		TStack<T> left, right;

		while (!Empty()) {
			std::shared_ptr<T> item = Pop_last();
			if (*item < *middle) {
				left.Push(item);
			}
			else {
				right.Push(item);
			}
		}

		std::future<void> left_res = left.sort_in_background();
		std::future<void> right_res = right.sort_in_background();


		left_res.get();


		while (!left.Empty()) Push(left.Pop_last());
		Push(middle);

		right_res.get();
		while (!right.Empty()) Push(right.Pop_last());

	}
}


template <class T> void TStack<T>::Push(std::shared_ptr<T> item) {
	std::shared_ptr<TStackItem < T >> other(new TStackItem<T>(item));
	other->SetNext(head);
	head = other;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {
	std::shared_ptr<TStackItem<T>> other = stack.head;
	while (other != nullptr){
		other->GetFigure()->Print();
		other = other->GetNext();
	}
	return os;
}

template <class T>
bool TStack<T>::Empty() {
	return (head == nullptr);
}

template <class T>
std::shared_ptr<T> TStack<T>::Pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		result = head->GetFigure();
		head = head->GetNext();
	}
	return result;
}

template <class T>
TStack<T>::~TStack<T>(){

}

template <class T>
void TStack<T>::Close(){
	while (!this->Empty()) {
		this->Pop();
	}
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::begin() {
	return TIterator<TStackItem<T>, T>(head);
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::end() {
	return TIterator<TStackItem<T>, T>(nullptr);
}

template <class T> size_t TStack<T>::size() {
	int result = 0;
	for (auto i : *this) result++;
	return result;
}


#include "FIGURE.H";

template class TStack<Figure>; 
template std::ostream& operator<<(std::ostream &out, const TStack<Figure> &obj);