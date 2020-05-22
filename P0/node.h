#pragma once
#ifndef P0_NODE_H
#define P0_NODE_H

#include <list>
#include <string>
#include <iosfwd>

class Node {
public:
  struct node {
    char data;
    node* left;
    node* right;
    std::list<std::string> tokens;

    node() : left(NULL), right(NULL) {}
  };

  Node() : root(NULL) {}

  bool isEmpty() const { return root == NULL; }

  void buildTree(const std::string&);

  void traverseInOrder(std::ostream & logFile);
  void traversePreOrder(std::ostream & logFile);
  void traverseLevelOrder(std::ostream & logFile);

  // public only for testing purposes. 
  node * getRoot() { return root; }

private:
  node* root;

  node * createNewNode(const std::string & word);

  void traverseInOrder(node * p, std::ostream & os, int depth);
  void traversePreOrder(node * p, std::ostream & os, int depth);
  void traverseLevelOrder(node * p, std::ostream & os);
};



#endif //P0_NODE_H
