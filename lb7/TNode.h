#ifndef TNODE_H
#define TNODE_H

#include <cstdlib>
#include <algorithm>

template <class T>
class TNode {
public:

	TNode * left;
	TNode*	right;
	TNode*	parent;

	T block;

	TNode(T block_t, TNode<T>* parent_t) {
		block = block_t;
		parent = parent_t;
		left = right = nullptr;
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