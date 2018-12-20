#include "TSTACKITEM.H"
#include <iostream>

template <class T>
TStackItem<T>::TStackItem(const std::shared_ptr<T> &obj){
	this->item = obj;
	this->next = nullptr;
}

template <class T>
std::shared_ptr<T> TStackItem<T>::GetFigure() const{
	return this->item;
}

template <class T>
std::shared_ptr<TStackItem<T>> TStackItem<T>::GetNext(){
	return this->next;
}

template <class T>
void TStackItem<T>::SetNext(std::shared_ptr<TStackItem<T>> item){
	this->next = item;
}

template <class T>
std::shared_ptr<T> TStackItem<T>::Remove() {
	std::shared_ptr<TStackItem<T>> overremove = this->next;
	std::shared_ptr<T> tmp = overremove->GetFigure();
	this->next = overremove->GetNext();
	return tmp;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TStackItem<T> &obj){
	os << obj.item << std::endl;
	return os;
}

template <class T> TAllocationBlock TStackItem<T>::stackitem_allocator(sizeof(TStackItem<T>), 100);

template <class T> void* TStackItem<T>::operator new(size_t size) {
	return stackitem_allocator.Allocate();
}

template <class T> void TStackItem<T>::operator delete(void* ptr) {
	return stackitem_allocator.Deallocate(ptr);
}



#include "FIGURE.H"
template class TStackItem<Figure>;
template std::ostream& operator<<(std::ostream &out, const TStackItem<Figure> &obj);
