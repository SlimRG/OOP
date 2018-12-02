#include <cstdlib>
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"


int main(int argc, char** argv) {

	// —читываем параметр фигуры
	size_t a, b, c;
	Figure * fig = NULL;
	switch (scanf_s("%Iu%Iu%Iu", &a, &b, &c)) {
	    case 3:
			fig = new Triangle(a, b, c);
			break;
		case 2:
			fig = new Rectangle(a, b);
			break;
		case 1:
			fig = new SquareF(a);
	}
	fig->Print();
	std::cout << fig->Square() << std::endl;
	delete fig;
	system("pause");
	return 0;
}
