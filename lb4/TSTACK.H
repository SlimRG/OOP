#ifndef TSTACK_H
#define	TSTACK_H

#include "FIGURE.H"
#include "TSTACKITEM.H"
#include <memory>

template <class T>
class TStack {
public:
	TStack();

	void Push(std::shared_ptr<T> &obj);
	bool Empty();
	std::shared_ptr<T> Pop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TStack<A>& stack);
	virtual ~TStack();
	void Close(); 

private:
	std::shared_ptr<TStackItem<T>> head;
};

#endif	
