#pragma once
#ifndef P0_NODE_H
#define P0_NODE_H

#include <list>
#include <string>

class Node {
public:
  struct node {
    char data;
    node* left;
    node* right;
    std::list<std::string> tokens;

    node() : left(NULL), right(NULL) {}
  };


  Node() {
    root = NULL;
  }

  Node::node * getRoot() { return root; }

  bool isEmpty() const { return root == NULL; }
  void buildTree(const std::string&);
  void formatOutput(int);
  void inorder(node*);
  void print_inorder();
  void preorder(node*);
  void print_preorder();
  void levelorder(node*);
  void print_levelorder();
private:
  node* root;

  node * createNewNode(const std::string & word);
};



#endif //P0_NODE_H
