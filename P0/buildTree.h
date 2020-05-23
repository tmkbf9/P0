#ifndef __BUILDTREE_H
#define __BUILDTREE_H

#include <string>
#include <iosfwd>

struct node;

class Node {
public:
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
  void traverseLevelOrder(node * p, std::ostream & os, int level, int depth);

  int height(node * p);
};

#endif
