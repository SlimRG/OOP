#include "TTriangle.h"

TTriangle::TTriangle() : side_a(0), side_b(0), side_c(0) {
}

TTriangle::TTriangle(size_t i, size_t j, size_t k) : side_a(i), side_b(j), side_c(k) {
}

TTriangle::TTriangle(const TTriangle &orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

TTriangle::TTriangle(std::istream &is) {
	is >> side_a;
	is >> side_b;
	is >> side_c;
}

double TTriangle::Square() {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(p * (p - double(side_a))*(p - double(side_b))*(p - double(side_c)));
}

void TTriangle::Print() {
	std::cout << "Треугольник:  ";
	std::cout << "a=" << side_a << ", b=" << side_b << ", c=" << side_c << std::endl;
}

unsigned char TTriangle::Type() {
	return 3;
}

TTriangle::~TTriangle() {
}

TTriangle& TTriangle::operator=(const TTriangle &right) {
	if (this == &right) return *this;
	side_a = right.side_a;
	side_b = right.side_b;
	side_c = right.side_c;
	return *this;
}

bool TTriangle::operator==(const TTriangle &obj) const {
	return
		((this->side_a == obj.side_a && this->side_b == obj.side_b && this->side_c == obj.side_c) ||
		 (this->side_a == obj.side_a && this->side_b == obj.side_c && this->side_c == obj.side_b) ||
		 (this->side_a == obj.side_b && this->side_b == obj.side_a && this->side_c == obj.side_c) ||
		 (this->side_a == obj.side_b && this->side_b == obj.side_c && this->side_c == obj.side_a) ||
		 (this->side_a == obj.side_c && this->side_b == obj.side_a && this->side_c == obj.side_b) ||
		 (this->side_a == obj.side_c && this->side_b == obj.side_b && this->side_c == obj.side_a));
}

bool  TTriangle::operator!=(const  TTriangle &obj) const {
    return !(*this == obj);
}

std::ostream& operator<<(std::ostream& os, const TTriangle& obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b << ", c=" << obj.side_c;
	return os;
}

std::istream& operator>>(std::istream& is, TTriangle& obj) {
	is >> obj.side_a;
	is >> obj.side_b;
	is >> obj.side_c;
	return is;
}