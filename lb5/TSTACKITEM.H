#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include <memory>
#include "FIGURE.H"

template <class T>
class TStackItem {
public:
	TStackItem(const std::shared_ptr<T> &obj);

	template <class A> friend std::ostream& operator<<(std::ostream &os, const TStackItem<A> &obj);

	std::shared_ptr<T> GetFigure() const;
	std::shared_ptr<TStackItem<T>> GetNext();

	void SetNext(std::shared_ptr<TStackItem<T>> item);

	std::shared_ptr<T> Remove();

	virtual ~TStackItem() {};
private:
	std::shared_ptr<T> item;
	std::shared_ptr<TStackItem<T>> next;
};

#endif	/* TSTACKITEM_H */

