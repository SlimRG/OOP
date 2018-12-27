#ifndef TTRIANGLE_H
#define TTRIANGLE_H

#include "Figure.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

class TTriangle : public Figure {
public:
	TTriangle();
	TTriangle(std::istream &is);
    TTriangle(size_t i, size_t j, size_t k);
	TTriangle(const TTriangle &orig);
	
	double        Square() override;
	void          Print()  override;
	unsigned char Type()   override;

	bool operator==(const TTriangle &obj) const;
	bool operator!=(const TTriangle &obj) const;

	friend std::ostream &operator<<(std::ostream &os, const TTriangle &obj);
	friend std::istream& operator>>(std::istream &is, TTriangle &obj);

	TTriangle& operator=(const TTriangle &right);

    virtual ~TTriangle() override;
      
private:
	size_t side_a;
	size_t side_b;
	size_t side_c;
};

#endif 