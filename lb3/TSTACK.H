#ifndef TSTACK_H
#define	TSTACK_H

#include "FIGURE.H"
#include "TSTACKITEM.H"
#include <memory>

class TStack {
public:
	TStack();
	//TStack(const TStack& orig);

	void Push(std::shared_ptr<Figure> &obj);
	bool Empty();
	std::shared_ptr<Figure> Pop();
	friend std::ostream& operator<<(std::ostream& os, const TStack& stack);
	virtual ~TStack();
	void Close(); 

private:
	std::shared_ptr<TStackItem> head;
};

#endif	
