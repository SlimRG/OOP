#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H

#include <cstdlib>
#include "TBTREE.H"

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

	char*   _used_blocks;
	TBTree* _free_blocks;
	size_t  _free_count;
};

#endif 
