#ifndef TBINTREE_H
#define TBINTREE_H

#include <cstdlib>
#include <memory>
#include <iostream>
#include "Figure.h"
#include "TNode.h"

template <class T>
class TBTree {
public:

	TBTree() {
		size = 0;
		root = nullptr;
	}

	void Push(T block_t) {
		Insert(block_t, &root, nullptr);
	}

	void Insert(T block_t, TNode<T>** node, TNode<T>* parent_t) {
		if(*node == nullptr) {
			size++;
			*node = new TNode<T>(block_t, parent_t);
		} else {
			if (*block_t >= *(*node)->block) Insert(block_t, &(*node)->right, *node);
			else Insert(block_t, &(*node)->left, *node);
		}
	}

	void Print(TNode<T>* node, int lvl) {
		if(node != nullptr) {
			Print(node->right, lvl + 1);

			for(int i = 1; i <= lvl; i++) printf_s("\t");
			node->block->Print();

			Print(node->left, lvl + 1);
		}
	}

	TNode<T>* FindPlace(TNode<T>* node) {
		if(node->left == nullptr) {
			if(node->right == nullptr) return node;
			else return FindPlace(node->right);
		} else return FindPlace(node->left);
	}
	
	T PopFind(TNode<T>* node) {
		if(node != nullptr) {
			if(node->left == nullptr) {
				if(node->right == nullptr) {
					if(node->parent != nullptr) {
						if(node->parent->left == node) 
							node->parent->left = nullptr;
						 else 
							node->parent->right = nullptr;
					} else root = nullptr;
					return node->block;
				} return PopFind(node->right);
			} return PopFind(node->left);
		}	else return nullptr;
	}

	T Pop() {
		size--;
		return PopFind(root);
	}

	~TBTree() {
		root->DestroyNode();
	}

	template <class A> friend std::ostream& operator<<(std::ostream& os, TBTree<A>& obj) {
		printf("-------- пюгдек ---------\n");
		obj.Print(obj.root, 0);
		printf("---- йнмеж пюгдекю -----\n");
		return os;
	}

	bool IsEmpty(){
		if (size != 0) return false; 
		else return true;
	}

	TNode<T>* root;
	size_t size;
};

template <class T>
class TBTree<T*> {
public:

	TBTree() {
		size = 0;
		root = nullptr;
	}

	void Push(T* block_t) {
		Insert(block_t, &root, nullptr);
	}

	void Insert(T* block_t, TNode<T*>** node, TNode<T*>* parent_t) {
		if(*node == nullptr) {
			size++;
			*node = new TNode<T*>(block_t, parent_t);
		}
		else {
			if (block_t >= (*node)->block) Insert(block_t, &(*node)->right, *node);
			else Insert(block_t, &(*node)->left, *node);
		}
	}

	void Print(TNode<T*>* node, int lvl) {
		if(node != nullptr) {
			Print(node->right, lvl + 1);

			for(int i = 0; i < lvl; i++) printf_s("\t");
			node->block->Print();

			Print(node->left, lvl + 1);
		}
	}

	TNode<T*>* FindPlace(TNode<T*>* node) {
		if(node->left == nullptr) {
			if(node->right == nullptr) return node;
			else return FindPlace(node->right);
		} return FindPlace(node->left);
	}
	
	bool IsEmpty(){
		return size == 0;
	}

	~TBTree() {
		root->DestroyNode();
	}
	
	template <class A> friend std::ostream& operator<<(std::ostream& os, TBTree<A>& obj) {
		printf("-------- пюгдек ---------\n");
		obj.Print(obj.root, 0);
		printf("---- йнмеж пюгдекю -----\n");
		return os;
	}

	TNode<T*>* root;
	size_t size;
};


#endif 
