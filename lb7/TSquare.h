#ifndef TSQUARE_H
#define TSQUARE_H

#include "Figure.h"
#include <iostream>
#include <cstdlib>

class TSquare : public Figure {
    public:
		TSquare();
		TSquare(std::istream &is);
		TSquare(size_t i);
		TSquare(const TSquare& orig);

		double        Square() override;
		void          Print()  override;
		unsigned char Type()   override;

		bool operator==(const TSquare &obj) const;
		bool operator!=(const TSquare &obj) const;

		friend std::ostream &operator<<(std::ostream &os, const TSquare &obj);
		friend std::istream& operator>>(std::istream &is, TSquare &obj);

		TSquare& operator=(const TSquare &orig);
		
		virtual ~TSquare() override;
    
    private:
		size_t side_a;
};
#endif 