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



void TestAllocationBlock() {
    std::cout << "Allocation Block Demonstration" << std::endl;
    
    TAllocationBlock allocator(sizeof(int), 10);
    int* a1 = nullptr;
    int* a2 = nullptr;
    int* a3 = nullptr;
    int* a4 = nullptr;
    int* a5 = nullptr;

    a1 = (int*) allocator.Allocate();
    *a1 = 1;
    std::cout << "a1 pointer value: " << *a1 << std::endl;
    a2 = (int*) allocator.Allocate();
    *a2 = 2;
    std::cout << "a2 pointer value: " << *a2 << std::endl;
    a3 = (int*) allocator.Allocate();
    *a3 = 3;
    std::cout << "a3 pointer value: " << *a3 << std::endl;

    allocator.Deallocate(a1);
    allocator.Deallocate(a3);

    a4 = (int*) allocator.Allocate();
    *a4 = 4;
    std::cout << "a4 pointer value: " << *a4 << std::endl;
    a5 = (int*) allocator.Allocate();
    *a5 = 5;
    std::cout << "a5 pointer value: " << *a5 << std::endl;

    std::cout << "a1 pointer value: " << *a1 << std::endl;
    std::cout << "a2 pointer value: " << *a2 << std::endl;
    std::cout << "a3 pointer value: " << *a3 << std::endl;

    allocator.Deallocate(a2);
    allocator.Deallocate(a4);
    allocator.Deallocate(a5);
}

void BenchmarAllcators() {
	std::cout << std::endl << "Benchmark" << std::endl;
	using namespace std::chrono;
	int** arr = (int**) malloc(sizeof(int*) * 1000);
	high_resolution_clock::time_point ownAllocBegin = high_resolution_clock::now();
	TAllocationBlock allocator(sizeof(int), 10000);
	for(int i = 0; i < 1000; i++) {
		arr[i] = (int*) allocator.Allocate();
	}
	for(int i = 0; i < 1000; i++) {
		allocator.Deallocate(arr[i]);
	}
	high_resolution_clock::time_point ownAllocEnd = high_resolution_clock::now();
	std::cout << duration_cast<microseconds>(ownAllocEnd - ownAllocBegin).count() << std::endl;
	high_resolution_clock::time_point AllocBegin = high_resolution_clock::now();
	std::vector <int*> vect(1000);
	for(int i = 0; i < 1000; i++) {
		vect[i] = (int*) malloc(sizeof(int));
	}
	for(int i = 0; i < 1000; i++) {
		free(vect[i]);
	}
	high_resolution_clock::time_point AllocEnd = high_resolution_clock::now();
	std::cout << duration_cast<microseconds>(AllocEnd - AllocBegin).count() << std::endl;
}

int main() {
    // TestAllocationBlock();
    // TesTStack();
    std::shared_ptr<Figure> ptr1 = std::make_shared<TRectangle>(1, 2);
    std::shared_ptr<Figure> ptr2 = std::make_shared<TTriangle>(1, 2, 3);
    std::shared_ptr<Figure> ptr3 = std::make_shared<TSquare>(1);
    std::shared_ptr<Figure> ptr4 = std::make_shared<TRectangle>(1, 2);
    std::shared_ptr<Figure> ptr5 = std::make_shared<TSquare>(2);
    std::shared_ptr<Figure> ptr6 = std::make_shared<TSquare>(3);
    std::shared_ptr<Figure> ptr7 = std::make_shared<TRectangle>(4, 2);
    std::shared_ptr<Figure> ptr8 = std::make_shared<TSquare>(3);
    std::shared_ptr<Figure> ptr9 = std::make_shared<TTriangle>(4, 2, 4);
    // tr.push(ptr1);
    // tr.push(ptr2);
    // tr.push(ptr3);  
    TStack < TBTree < std::shared_ptr <Figure> >, Figure > tq;
    tq.Pop(ptr1);
    tq.Insert(ptr2);
    tq.Insert(ptr3);
    tq.Insert(ptr4);
    tq.Insert(ptr5);
    tq.Insert(ptr6);
    tq.Insert(ptr7);
    tq.Insert(ptr8);
    tq.Insert(ptr9);
    std::cout << tq << std::endl;
    IRemoveCriteriaBySquare<double> criteria(2.0);
    tq.RemoveItemSq(&criteria);
    std::cout << tq << std::endl;
    IRemoveCriteriaAll<Figure, TSquare> criteriaAll;
    tq.RemoveItemAll(&criteriaAll);
    std::cout << tq << std::endl;
	return 0;
}
