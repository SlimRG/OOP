#include "TRectangle.h"

TRectangle::TRectangle() : TRectangle(0, 0) {
}

TRectangle::TRectangle(size_t i, size_t j) : side_a(i), side_b(j) {
}

TRectangle::TRectangle(std::istream &is) {
	is >> side_a;
	is >> side_b;
}

TRectangle::TRectangle(const TRectangle &orig) {
    side_a = orig.side_a;
    side_b = orig.side_b;
}


double TRectangle::Square() {
	double p = side_a * side_b;
	return p;
}

void TRectangle::Print() {
	std::cout << "Прямоугольник:" << std::endl;
	std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

unsigned char TRectangle::Type() {
	return 2;
}

TRectangle& TRectangle::operator=(const TRectangle &right) {
	if (this == &right)	return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	return *this;
}

bool TRectangle::operator==(const TRectangle &obj) const {
	return ((this->side_a == obj.side_a && this->side_b == obj.side_b) || (this->side_a == obj.side_b && this->side_b == obj.side_a));
}


bool TRectangle::operator!=(const TRectangle &obj) const {
	return !(*this == obj);
}

std::ostream &operator<<(std::ostream &os, const TRectangle &obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b;
	return os;
}

std::istream &operator>>(std::istream &is, TRectangle &obj) {
	is >> obj.side_a;
	is >> obj.side_b;
	return is;
}



TRectangle::~TRectangle() {}











