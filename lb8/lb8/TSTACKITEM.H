#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include <memory>
#include <iostream>
#include "FIGURE.H"
#include "TALLOCATIONBLOCK.H"

template <class T>
class TStackItem {
public:
	TStackItem(std::shared_ptr<T> item);
	TStackItem(T *item);
	template <class A> friend std::ostream& operator<<(std::ostream &os, const TStackItem<A> &obj);

	std::shared_ptr<T> GetFigure() const;
	std::shared_ptr<TStackItem<T>> GetNext();
	std::shared_ptr<T> GetValue() const;

	void SetNext(std::shared_ptr<TStackItem<T>> item);

	std::shared_ptr<T> Remove();


	void* operator new(size_t size);
	void operator delete(void* ptr);

	virtual ~TStackItem() {};
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TStackItem<T>> next;

	static TAllocationBlock stackitem_allocator;
};

#endif	/* TSTACKITEM_H */

