#include "TSquare.h"

TSquare::TSquare() : TSquare(0) {
}

TSquare::TSquare(size_t i) : side_a(i) {
}

TSquare::TSquare(std::istream &is) {
	is >> side_a;
}

TSquare::TSquare(const TSquare &orig) {
	side_a = orig.side_a;
}

double TSquare::Square() {
	double p = side_a * side_a;
	return p;
}

void TSquare::Print() {
	std::cout << " вадрат:" << std::endl;
	std::cout << "a=b=c=d=" << side_a << std::endl;
}

unsigned char TSquare::Type() {
	return 1;
}

TSquare::~TSquare() {
}

TSquare& TSquare::operator=(const TSquare& right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	return *this;
}

bool TSquare::operator==(const TSquare& obj) const {
	return (side_a == obj.side_a);
}

bool TSquare::operator!=(const TSquare &obj) const {
    return !(*this == obj);
}

std::ostream& operator<<(std::ostream &os, const TSquare &obj) {
	os << "a=b=c=d= " << obj.side_a;
	return os;
}

std::istream& operator>>(std::istream &is, TSquare &obj) {
	is >> obj.side_a;
	return is;
}

