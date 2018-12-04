#include "TStack.h"
#include <memory>

TStack::TStack() {
	head = nullptr;
}

/*
TStack::TStack(const TStack& orig) {
	head = orig.head;
}
*/

void TStack::Push(std::shared_ptr<Figure> &obj) {
	std::shared_ptr<TStackItem> other = std::make_shared<TStackItem>(obj);
	other->SetNext(head);
	head = other;
}

std::ostream& operator<<(std::ostream& os, const TStack& stack) {
	std::shared_ptr<TStackItem> other = stack.head;
	while (other != nullptr){
		other->GetFigure()->Print();
		other = other->GetNext();
	}
	return os;
}

bool TStack::Empty() {
	return (head == nullptr);
}

std::shared_ptr<Figure> TStack::Pop() {
	std::shared_ptr<Figure> result;
	if (head != nullptr) {
		result = head->GetFigure();
		head = head->GetNext();
	}
	return result;
}

TStack::~TStack(){

}

void TStack::Close()
{
	while (!this->Empty()) {
		this->Pop();
	}
}