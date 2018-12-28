#include <iostream>
#include "TALLOCATIONBLOCK.h"

TAllocationBlock::TAllocationBlock(size_t size, size_t count) : _size(size), _count(count) {
	_used_blocks = (char*)malloc(_size * _count);

	_free_blocks = new TBTree();

	for (size_t i = _count / 2; i < _count; i++) {
		_free_blocks->InsertLeaf(_used_blocks + i * _size, &(_free_blocks->root), nullptr);
	}
	for (size_t i = 0; i < _count / 2; i++) {
		_free_blocks->InsertLeaf(_used_blocks + i * _size, &(_free_blocks->root), nullptr);
	}

	_free_count = _count;
	std::cout << "TAllocationBlock: Memory init" << std::endl;
}

void* TAllocationBlock::Allocate() {
	void* result = nullptr;
	if (_free_count > 0) {
		TNode* node;

		node = _free_blocks->FindLeaf(_free_blocks->root);
		result = node->block;

		if (node->parent == nullptr) _free_blocks->root = nullptr;
		else if (node->parent->left == node) node->parent->left = nullptr;
		else node->parent->right = nullptr;
		
		delete node;
		_free_count--;

		std::cout << "TAllocationBlock: Allocate" << std::endl;
	}
	else {
		std::cout << "TAllocationBlock: No Memory" << std::endl;
	}
	return result;
}

void TAllocationBlock::Deallocate(void* ptr) {
	std::cout << "TAllocationBlock: Deallocate" << std::endl;
	_free_blocks->InsertLeaf((char*)ptr, &(_free_blocks->root), nullptr);
	_free_count++;
}

bool TAllocationBlock::IsEmpty() {
	return _free_count > 0;
}

TAllocationBlock::~TAllocationBlock() {

	// Лог, не забыть закомментить эту ерись
	// -----------------------------------------------------------------
	if (_free_count < _count) {
		std::cout << "TAllocationBlock: Memory Leak" << std::endl;
	}
	else {
		std::cout << "TAllocationBlock: Memory free" << std::endl;
	}
	// -----------------------------------------------------------------

	delete _used_blocks;
	delete _free_blocks;
}