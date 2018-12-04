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

	virtual ~SquareF();
private:
	size_t side_a;
};


#endif	