#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

#include <memory>
#include "FIGURE.H"
class TStackItem {
public:
	//TStackItem(const Triangle& triangle);
	TStackItem(const std::shared_ptr<Figure> &obj);

	friend std::ostream& operator<<(std::ostream &os, const TStackItem &obj);

	std::shared_ptr<Figure> GetFigure() const;
	std::shared_ptr<TStackItem> GetNext();

	void SetNext(std::shared_ptr<TStackItem> item);

	//Triangle GetTriangle() const;

	virtual ~TStackItem();
private:
	std::shared_ptr<Figure> item;
	std::shared_ptr<TStackItem> next;
};

#endif	/* TSTACKITEM_H */
