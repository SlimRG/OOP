#include "TAllocationBlock.h"
#include <iostream>

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {

	_used_blocks = (char*) malloc(_size * _count);
	_free_blocks = new TBTree<void*>();

	for(size_t i = _count / 2; i < _count; i++) {
		_free_blocks->Insert((void*) (_used_blocks + i * _size), &(_free_blocks->root), nullptr);
	}

	for(size_t i = 0; i < _count / 2; i++) {
		_free_blocks->Insert((void*) (_used_blocks + i * _size), &(_free_blocks->root), nullptr);
	}

	_free_count = _count;

	// Ћог
	//-------------------------------------------------------
	std::cout << "TAllocationBlock: Memory init" << std::endl;
	
}

void* TAllocationBlock::Allocate() {
	void* result = nullptr;

	if(_free_count > 0) {
		TNode<void*>* node;

		node = _free_blocks->FindPlace( _free_blocks->root );
		result = node->block;

		if(node->parent == nullptr) _free_blocks->root = nullptr;
		else if (node->parent->right == node) node->parent->right = nullptr;
		else node->parent->left = nullptr;

		_free_count--;
		delete node;
		
		// Ћог
		//-------------------------------------------------------
		std::cout << "TAllocationBlock: Allocate" << std::endl;
		//-------------------------------------------------------
	} else std::cout << "TAllocationBlock: No Memory" << std::endl;
	
	return result;
}

void TAllocationBlock::Deallocate(void* ptr) {
	_free_blocks->Insert( (void*)ptr, &(_free_blocks->root), nullptr);
	_free_count++;

	// Ћог
	//-------------------------------------------------------
	std::cout << "TAllocationBlock: Deallocate" << std::endl;
	//-------------------------------------------------------
}

bool TAllocationBlock::IsEmpty() {
	if (_free_count == 0) return false;
	else return true;
}

TAllocationBlock::~TAllocationBlock() {
	// Ћог
	//-------------------------------------------------------
	if(_free_count < _count) std::cout << "TAllocationBlock: Memory Leak" << std::endl;
	 else std::cout << "TAllocationBlock: Memory free" << std::endl;
	//-------------------------------------------------------

	delete _free_blocks;
	delete _used_blocks;	
}
