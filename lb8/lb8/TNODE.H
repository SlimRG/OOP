#ifndef TNODE_H
#define TNODE_H

#include <cstdlib>
#include <algorithm>

struct TNode {
	TNode* left;
	TNode* right;
	TNode* parent;
	void* block;


	TNode(char* block_t, TNode* parent_t) {
		block = block_t;
		parent = parent_t;
		right = left = nullptr;
	}

	void DestroyNode() {
		if (this != nullptr) {
			right->DestroyNode();
			left->DestroyNode();
			delete this;
		}
	}

	~TNode() {
	}
};

#endif