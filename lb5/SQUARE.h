#ifndef SQUARE_H
#define	SQUARE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"


class SquareF : public Figure {
public:
	SquareF();
	SquareF(std::istream &is);
	SquareF(size_t i);
	SquareF(const SquareF &orig);

	double Square() override;
	void   Print() override;

	bool operator ==(const SquareF &obj) const;

	friend std::ostream& operator<<(std::ostream& os, const SquareF& obj);
	friend std::istream& operator>>(std::istream& is, SquareF& obj);

	SquareF& operator =(const SquareF &right);

	virtual ~SquareF();
private:
	size_t side_a;
};


#endif	