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


	std::cout << "���� �����!" << std::endl;
	std::cout << "�������:\n" << std::endl;
	std::cout << "T  - ���� ������������" << std::endl;
	std::cout << "R  - ���� ��������������" << std::endl;
	std::cout << "S  - ���� ��������" << std::endl;
	std::cout << "D  - ������� �������" << std::endl;
	std::cout << "A  - ������� ��� �������� �����" << std::endl;
	std::cout << "E! - �����" << std::endl << std::endl;

	firstkey = '0';
	while (exitkey == false) {
		if (firstkey >= '0') printf("T>");
		scanf_s("%c", &firstkey);

		switch (firstkey) {
		case 'T':
			std::cout << "������� ��������� ������������:" << std::endl;
			sptr = std::make_shared<Triangle>(std::cin);
			cookie.Push(sptr);
			break;
		case 'R':
			std::cout << "������� ��������� ��������������:" << std::endl;
			sptr = std::make_shared<Rectangle>(std::cin);
			cookie.Push(sptr);
			break;
		case 'S':
			std::cout << "������� ��������� ��������:" << std::endl;
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
			} else std::cout << "�� �������� �������������!" << std::endl;
			break;
		}
	}
	return 0;
}