#include "TStack.h"
#include <memory>

template <class T>
TStack<T>::TStack() {
	head = nullptr;
}

/*
TStack::TStack(const TStack& orig) {
	head = orig.head;
}
*/

template <class T>
void TStack<T>::Push(std::shared_ptr<T> &obj) {
	std::shared_ptr<TStackItem<T>> other = std::make_shared<TStackItem<T>>(obj);
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


#include "FIGURE.H";
template class TStack<Figure>; 
template std::ostream& operator<<(std::ostream &out, const TStack<Figure> &obj);