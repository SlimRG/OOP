#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TBTree.h"

class TAllocationBlock {
public:
	TAllocationBlock(size_t size, size_t count);

	void* Allocate();
	void  Deallocate(void* ptr);
	bool  IsEmpty();

	virtual ~TAllocationBlock();

private:
	size_t _size;
	size_t _count;
	size_t _free_count;

	char* _used_blocks;

	TBTree<void*>* _free_blocks;

	
};

#endif 