#pragma once
#ifndef P0_NODE_H
#define P0_NODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <set>
#include <queue>
//#include <stdio.h>

using namespace std;

class Node {
private:
	struct node {
		node* left;
		node* right;
		char data;
		std::set<string> myset;
	};

	node* root;

public:
	Node() {
		root = NULL;
	}

	bool isEmpty() const { return root == NULL; }
	void buildTree(char);
	void formatOutput(int);
	void inorder(node*);
	void print_inorder();
	void preorder(node*);
	void print_preorder();
	void levelorder(node*);
	void print_levelorder();


};



#endif //P0_NODE_H