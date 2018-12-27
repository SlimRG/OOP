#ifndef TSTACK_H
#define TSTACK_H

#include "Figure.h"
#include "TRectangle.h"
#include "TSquare.h"
#include "TTriangle.h"
#include "TStackItem.h"
#include "TIterator.h"
#include "TBTree.h"
#include "TNode.h"
#include "IRemoveCriteria.h"
#include "IRemoveCriteriaAll.h"
#include <memory>

template <class T, class TT> class TStack {
public:
	TStack();
	virtual ~TStack();

	template<class A, class AA> friend std::ostream& operator<<(std::ostream& os, TStack<A, AA>& stack);

	void Push(std::shared_ptr<T> container);

	void Insert(std::shared_ptr<TT> obj);
	bool Empty();
	void Pop();
	std::shared_ptr<T> Front();

	TIterator < TStackItem<T>, T > begin();
	TIterator < TStackItem<T>, T > end();


	void RemoveItemSq(IRemoveCriteria<double>* criteria);

	template <class A> void RemoveItemAll(IRemoveCriteriaAll<TT, A>* criteria) {
		for (auto i : *this) {
			T copy;
			while (!i->IsEmpty()) {
				std::shared_ptr<TT> value = i->Pop();
				if (criteria->isIt(&*value)) {
					std::cout << "Delete item" << std::endl;
				}
				else {
					copy.Push(value);
				}
			}
			while (!copy.IsEmpty()) {
				i->Push(copy.Pop());
			}
		}
	}
	

private:
	std::shared_ptr < TStackItem <T> > head;
	size_t size;
};

#endif 