#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>

#include "node.h"

using namespace std;

void Node::buildTree(const string & word)
{

  // is this a new tree?
  if (isEmpty()) {
    root = createNewNode(word);
  }
  else
    {
      //Note: ALL insertions are as leaf nodes
      node * parent = NULL;
      node* curr = root;
      char firstLetter = word.at(0);

      // Find the Node's parent
      while (curr)
	{
	  parent = curr;
	  if (firstLetter > curr->data) curr = curr->right;
	  else if(firstLetter < curr->data) curr = curr->left;
	  else {
	    curr->tokens.push_back(word);
	    return;
	  }
	}

      node * newNode = createNewNode(word);
      if (newNode->data < parent->data)
	parent->left = newNode;
      else
	parent->right = newNode;
    }
}

Node::node * Node::createNewNode(const string & word) {
  Node::node* t = new Node::node();

  t->data = word.at(0);
  t->left = NULL;
  t->right = NULL;
  t->tokens.push_back(word);

  return t;
}

void Node::formatOutput(int depth)
{

}

void Node::traverseInOrder(ostream & logFile)
{
  traverseInOrder(getRoot(), logFile);
}

void Node::traverseInOrder(Node::node * p, ostream & logFile) {
  if (p != NULL)
    {
      if (p->left) {
	traverseInOrder(p->left, logFile);
	cout << " " << p->data << " ";
      }
		
      logFile << p->data;
      if (p->right) traverseInOrder(p->right, logFile);
    }
}

void Node::traversePreOrder(ostream & logFile)
{
  traversePreOrder(getRoot(), logFile);
}

void Node::traversePreOrder(Node::node * p, ostream & logFile) {
  if (p != NULL)
    {
      cout << " " << p->data << " ";
      logFile << p->data;
      if (p->left) traversePreOrder(p->left, logFile);
      if (p->right) traversePreOrder(p->right, logFile);
    }
}

void Node::traverseLevelOrder(ostream & logFile)
{
  traverseLevelOrder(getRoot(), logFile);
}

void Node::traverseLevelOrder(Node::node * p, ostream & logFile) {
  if (p != NULL)
    {	
      queue<node*> que;
      que.push(p);
      while (que.empty() == false)
	{
	  int count = que.size();
	  while (count > 0)
	    {
	      node* node = que.front();
	      cout << " " << node->data << " ";
	      logFile << node->data;
	      que.pop();
	      if (node->left != NULL)
		que.push(node->left);
	      if (node->right != NULL)
		que.push(node->right);
	      count--;
	    }
	}
    }
}
