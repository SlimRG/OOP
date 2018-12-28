#ifndef TBTREE_H
#define TBTREE_H

#include <cstdlib>
#include "TNODE.H"

class TBTree {
public:
	TBTree() {
		root = nullptr;
	}

	void InsertLeaf(char* block_t, TNode** node, TNode* par) {
		if (*node == nullptr) {
			*node = new TNode(block_t, par);
			return;
		}

		if (block_t >= (*node)->block) InsertLeaf(block_t, &(*node)->right, *node);
	      else InsertLeaf(block_t, &(*node)->left, *node);
		
	}

	TNode* FindLeaf(TNode* node) {
		if (node->left == nullptr) {
			if (node->right == nullptr) {
				return node;
			} else return FindLeaf(node->right);
		} else return FindLeaf(node->left);
	}

	~TBTree() {
		root->DestroyNode();
	}

	TNode* root;
};

#endif 