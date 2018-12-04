#include "RECTANGLE.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle() :Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
	std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
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
