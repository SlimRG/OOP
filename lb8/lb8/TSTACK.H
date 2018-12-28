#ifndef TSTACK_H
#define	TSTACK_H

#include "FIGURE.H"
#include "TSTACKITEM.H"
#include <memory>
#include <future>
#include <mutex>


#include "TIterator.h"

template <class T>
class TStack {
public:
	TStack();

	void Push(std::shared_ptr<T> obj);
	bool Empty();
	std::shared_ptr<T> Pop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TStack<A>& stack);
	virtual ~TStack();
	void Close();
	size_t size();
	void sort();
	void sort_parallel();

	std::shared_ptr<T> Pop_last();

	void Push(T* item);

	TIterator<TStackItem<T>, T> begin();
	TIterator<TStackItem<T>, T> end();
private:
	std::shared_ptr<TStackItem<T>> head;
	std::future<void> sort_in_background();
};

#endif	
