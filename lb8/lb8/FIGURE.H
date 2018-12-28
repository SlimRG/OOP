#ifndef FIGURE_H
#define	FIGURE_H

class Figure {
public:
	virtual double Square() = 0;
	virtual void   Print() = 0;
	virtual ~Figure() {};
	bool operator<(Figure& s) {
		return this->Square() < s.Square();
	}
};

#endif	/* FIGURE_H */

