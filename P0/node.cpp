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

void Node::print_inorder()
{
  cout << "Inorder:";
  inorder(root);
}

void Node::inorder(node* p)
{
  int depth = 0;
  ofstream logFile("out.inorder");
  if (p != NULL && logFile.is_open())
    {
      if (p->left) {
	inorder(p->left);
	cout << " " << p->data << " ";
      }
		
      logFile << p->data;
      if (p->right) inorder(p->right);
      logFile.close();
    }
  else return;
}

void Node::print_preorder()
{
  cout << "Preorder:";
  preorder(root);
}

void Node::preorder(node* p)
{
  ofstream logFile("out.preorder");
  if (p != NULL && logFile.is_open())
    {
      cout << " " << p->data << " ";
      logFile << p->data;
      if (p->left) preorder(p->left);
      if (p->right) preorder(p->right);
      logFile.close();
    }
  else return;
}

void Node::print_levelorder()
{
  cout << "Level Order:";
  levelorder(root);
}

void Node::levelorder(node* p)
{
  ofstream logFile("out.levelorder");
  if (p != NULL && logFile.is_open())
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
