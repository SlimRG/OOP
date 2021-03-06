#include <cstdlib>
#include <iostream>

#include "Triangle.h"
#include "FIGURE.H"
#include "TStackItem.h"
#include "TStack.h"

// Simple stack on pointers
int main(int argc, char** argv) {

	TStack stack;



	stack.push(Triangle(1, 1, 1));
	stack.push(Triangle(2, 2, 2));
	stack.push(Triangle(3, 3, 3));

	std::cout << stack;

	
	Triangle t;

	t = stack.pop(); std::cout << t << std::endl;
	t = stack.pop(); std::cout << t << std::endl;
	t = stack.pop(); std::cout << t << std::endl;

	

	system("pause");
	return 0;
}
