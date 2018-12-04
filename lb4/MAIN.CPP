#include <cstdlib>
#include <iostream>
#include <memory>

#include "FIGURE.H"
#include "TRIANGLE.H"
#include "RECTANGLE.H"
#include "SQUARE.H"

#include "TSTACK.H"


int main(int argc, char** argv) {

	bool exitkey = false;
	char firstkey;
	std::shared_ptr<Figure> sptr;
	TStack<Figure> cookie;


	setlocale(LC_CTYPE, "rus");


	std::cout << "Всем бобра!" << std::endl;
	std::cout << "Функции:\n" << std::endl;
	std::cout << "T  - ввод треугольника" << std::endl;
	std::cout << "R  - ввод прямоугольника" << std::endl;
	std::cout << "S  - ввод квадрата" << std::endl;
	std::cout << "D  - удалить элемент" << std::endl;
	std::cout << "A  - вывести все элементы стека" << std::endl;
	std::cout << "E! - выход" << std::endl << std::endl;

	firstkey = '0';
	while (exitkey == false) {
		if (firstkey >= '0') printf("T>");
		scanf_s("%c", &firstkey);

		switch (firstkey) {
		case 'T':
			std::cout << "Введите параметры треугольника:" << std::endl;
			sptr = std::make_shared<Triangle>(std::cin);
			cookie.Push(sptr);
			break;
		case 'R':
			std::cout << "Введите параметры прямоугольника:" << std::endl;
			sptr = std::make_shared<Rectangle>(std::cin);
			cookie.Push(sptr);
			break;
		case 'S':
			std::cout << "Введите параметры квадрата:" << std::endl;
			sptr = std::make_shared<SquareF>(std::cin);
			cookie.Push(sptr);
			break;
		case 'D':
			cookie.Pop();
			break;
		case 'A':
			std::cout << cookie << std::endl;
			break;
		case 'E':
			scanf_s("%c", &firstkey);
			if (firstkey == '!') {
				cookie.Close();
				exitkey = true;
			} else std::cout << "Не получено подтверждения!" << std::endl;
			break;
		}
	}
	return 0;
}