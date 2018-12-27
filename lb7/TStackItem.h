#ifndef TSTACKITEM_H
#define TSTACKITEM_H

#include "Figure.h"
#include "TAllocationBlock.h"
#include <iostream>
#include <memory>
#include "TBTree.h"
#include "TNode.h"

template <class T> class TStackItem {
public:
	TStackItem(const std::shared_ptr<T> &obj);

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TStackItem<A>& obj);

	std::shared_ptr<TStackItem<T>> GetNext();
	std::shared_ptr<T> GetFigure() const;
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

#endif 
