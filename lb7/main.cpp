#include <iostream>
#include <cstdlib>
#include <memory>
#include <ratio>
#include <chrono>
#include <vector>

#include "TStack.h"
#include "TBTree.h"
#include "TStackItem.h"
#include "TRectangle.h"
#include "TTriangle.h"
#include "TSquare.h"
#include "Figure.h"
#include "IRemoveCriteria.h"
#include "IRemoveCriteriaBySquare.h"
#include "IRemoveCriteriaAll.h"

int main(int argc, char** argv) {

	setlocale(LC_CTYPE, "rus");

	TStack < TBTree < std::shared_ptr <Figure> >, Figure > cookie;


	std::shared_ptr<Figure> ptr1 = std::make_shared<TRectangle>(1, 2);
	std::shared_ptr<Figure> ptr2 = std::make_shared<TSquare>(1);
	std::shared_ptr<Figure> ptr3 = std::make_shared<TTriangle>(1, 2, 3);
	std::shared_ptr<Figure> ptr4 = std::make_shared<TRectangle>(2, 3);
	std::shared_ptr<Figure> ptr5 = std::make_shared<TSquare>(2);
	std::shared_ptr<Figure> ptr6 = std::make_shared<TSquare>(3);
	std::shared_ptr<Figure> ptr7 = std::make_shared<TRectangle>(5, 6);
	std::shared_ptr<Figure> ptr8 = std::make_shared<TTriangle>(3, 2, 1);
	std::shared_ptr<Figure> ptr9 = std::make_shared<TSquare>(8);
	
	std::shared_ptr<Figure> ptr10 = std::make_shared<TRectangle>(1, 2);
	std::shared_ptr<Figure> ptr20= std::make_shared<TSquare>(1);
	std::shared_ptr<Figure> ptr30 = std::make_shared<TTriangle>(1, 2, 3);
	std::shared_ptr<Figure> ptr40 = std::make_shared<TRectangle>(2, 3);
	std::shared_ptr<Figure> ptr50 = std::make_shared<TSquare>(2);
	std::shared_ptr<Figure> ptr60 = std::make_shared<TSquare>(3);
	std::shared_ptr<Figure> ptr70 = std::make_shared<TRectangle>(5, 6);
	std::shared_ptr<Figure> ptr80 = std::make_shared<TTriangle>(3, 2, 1);
	std::shared_ptr<Figure> ptr90 = std::make_shared<TSquare>(8);
	
	cookie.Insert(ptr1);
	cookie.Insert(ptr2);
	cookie.Insert(ptr3);
	cookie.Insert(ptr4);
	cookie.Insert(ptr5);
	cookie.Insert(ptr6);
	cookie.Insert(ptr7);
	cookie.Insert(ptr8);
	cookie.Insert(ptr9);
	std::cout << cookie << std::endl;
	/*
	std::cout << cookie << std::endl;

	cookie.Insert(ptr10);
	cookie.Insert(ptr20);
	cookie.Insert(ptr30);
	cookie.Insert(ptr40);
	cookie.Insert(ptr50);
	cookie.Insert(ptr60);
	cookie.Insert(ptr70);
	cookie.Insert(ptr80);
	cookie.Insert(ptr90);

	*/



	std::cout << std::endl;
	IRemoveCriteriaBySquare<double> criteria(2);
	std::cout << std::endl;
	cookie.RemoveItemSq(&criteria);
	std::cout << std::endl;
	std::cout << cookie << std::endl;
	std::cout << std::endl;
	IRemoveCriteriaAll<Figure, TSquare> criteriaAll;
	std::cout << std::endl;
	cookie.RemoveItemAll(&criteriaAll);
	std::cout << cookie << std::endl;
	
	system("pause");
	return 0;
}


