#include "Square.h"
#include <iostream>
#include <cmath>

SquareF::SquareF() : SquareF(0) {
}

SquareF::SquareF(size_t i) : side_a(i){
	//std::cout << "Square created: " << side_a << std::endl;
}

SquareF::SquareF(std::istream &is) {
	is >> side_a;
}

SquareF::SquareF(const SquareF &orig) {
	//std::cout << "Square copy created" << std::endl;
	side_a = orig.side_a;
}

double SquareF::Square() {
	double p = side_a * side_a;
	return p;
}

void SquareF::Print() {
	std::cout << " вадрат:" << std::endl;
	std::cout << "a=b=c=d=" << side_a << std::endl;
}

SquareF::~SquareF() {
	//::cout << "Square deleted" << std::endl;
}

SquareF& SquareF::operator=(const SquareF& right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const SquareF &obj){
	os << "a=b=c=d= " << obj.side_a;
	return os;
}

std::istream& operator>>(std::istream &is, SquareF &obj){
	is >> obj.side_a;
	return is;
}

bool SquareF::operator==(const SquareF& obj) const {
	return (side_a == obj.side_a);
}