#include "RECTANGLE.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() :Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
	//std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
	is >> side_a;
	is >> side_b;
}

Rectangle::Rectangle(const Rectangle &orig) {
	//std::cout << "Rectangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
}

double Rectangle::Square() {
	double p = side_a * side_b;
	return p;
}

void Rectangle::Print() {
	std::cout << "Прямоугольник:" << std::endl;
	std::cout << "a=" << side_a << ", b=" << side_b << std::endl;
}

Rectangle::~Rectangle() {
	//std::cout << "Rectangle deleted" << std::endl;
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
	if (this == &right) return *this;
	//std::cout << "Triangle copied" << std::endl;
	side_a = right.side_a;
	side_b = right.side_b;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "a=" << obj.side_a << ", b=" << obj.side_b;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
	is >> obj.side_a;
	is >> obj.side_b;
	return is;
}

bool Rectangle::operator==(const Rectangle& obj) const {
	return ((side_a == obj.side_a) && (side_b == obj.side_b));
}