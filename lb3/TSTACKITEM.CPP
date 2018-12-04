#include "TSTACKITEM.H"
#include <iostream>

TStackItem::TStackItem(const std::shared_ptr<Figure> &obj){
	this->item = obj;
	this->next = nullptr;
}

std::shared_ptr<Figure> TStackItem::GetFigure() const{
	return this->item;
}

std::shared_ptr<TStackItem> TStackItem::GetNext(){
	return this->next;
}

void TStackItem::SetNext(std::shared_ptr<TStackItem> item){
	this->next = item;
}

std::ostream& operator<<(std::ostream &os, const TStackItem &obj){
	os << obj.item << std::endl;
	return os;
}