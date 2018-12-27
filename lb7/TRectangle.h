#ifndef TRECTANGLE_H
#define TRECTANGLE_H

#include "Figure.h"
#include <iostream>
#include <cstdlib>

class TRectangle : public Figure {
    public:
        TRectangle();
		TRectangle(std::istream &is);
        TRectangle(size_t i, size_t j);
        TRectangle(const TRectangle &orig);

		double        Square() override;
		void          Print()  override;
		unsigned char Type()   override;

		bool operator==(const TRectangle &obj) const;
		bool operator!=(const TRectangle &obj) const;

		friend std::ostream &operator<<(std::ostream &os, const TRectangle &obj);
		friend std::istream& operator>>(std::istream &is, TRectangle &obj);

		TRectangle& operator=(const TRectangle &original);

        virtual ~TRectangle() override;
  
    private:
        double side_a;
        double side_b;
};
#endif 
