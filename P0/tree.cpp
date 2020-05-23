#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>

#include "node.h"

using namespace std;

namespace {
  string join(const list<string>& tokens) {
    string concatenatedTokens;
    list<string>::const_iterator it;
    for (it = tokens.begin(); it != tokens.end(); ++it) {
      concatenatedTokens += (*it + " ");
    }
    
    return concatenatedTokens;
  }
  
  string blanks(int count) {
    string blanks = "";
	
    for (int i = 0; i < count; i++) {
      blanks += "  ";
    }
    
    return blanks;
  }
}

void Node::buildTree(const string& word)
{

    // is this a new tree?
    if (isEmpty()) {
        root = createNewNode(word);
    }
    else
    {
        //Note: ALL insertions are as leaf nodes
        node* parent = NULL;
        node* curr = root;
        char firstLetter = word.at(0);

        // Find the Node's parent
        while (curr)
        {
            parent = curr;
            if (firstLetter > curr->data) curr = curr->right;
            else if (firstLetter < curr->data) curr = curr->left;
            else {
                curr->tokens.push_back(word);
                return;
            }
        }

        node* newNode = createNewNode(word);
        if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
}

Node::node* Node::createNewNode(const string& word) {
    Node::node* t = new Node::node();

    t->data = word.at(0);
    t->left = NULL;
    t->right = NULL;
    t->tokens.push_back(word);

    return t;
}

void Node::traverseInOrder(ostream& logFile)
{
    traverseInOrder(getRoot(), logFile, 0);
}

void Node::traverseInOrder(Node::node* p, ostream& logFile, int depth) {
    if (p == NULL) return;

    if (p->left != NULL) {
        traverseInOrder(p->left, logFile, depth + 1);
    }

    logFile << blanks(depth) << depth + 1 << " " << p->data << " " << join(p->tokens) << endl;

    if (p->right != NULL) {
        traverseInOrder(p->right, logFile, depth + 1);
    }
}

void Node::traversePreOrder(ostream& logFile)
{
    traversePreOrder(getRoot(), logFile, 0);
}

void Node::traversePreOrder(Node::node* p, ostream& logFile, int depth) {
    if (p == NULL) return;
    
    logFile << blanks(depth) << depth + 1 << " " << p->data << " " << join(p->tokens) << endl;

    if (p->left != NULL) {
        traversePreOrder(p->left, logFile, depth + 1);
    }
    if (p->right != NULL) { 
        traversePreOrder(p->right, logFile, depth + 1); 
    }

}

void Node::traverseLevelOrder(ostream& logFile)
{
    int h = height(getRoot());
    int i;
    for (i = 1; i <= h; i++) {
        traverseLevelOrder(getRoot(), logFile, i, i - 1);
    }
    
}

void Node::traverseLevelOrder(Node::node* p, ostream& logFile, int level, int depth) {
        if (p == NULL) return;
        if (level == 1) {
            logFile << blanks(depth) << depth + 1 << " " << p->data << " " << join(p->tokens) << endl;
        }
        else if (level > 1)
        {
            traverseLevelOrder(p->left, logFile, level - 1, depth);
            traverseLevelOrder(p->right, logFile, level - 1, depth);
        }   
}

int Node::height(Node::node* p) {
  if(p == NULL) return 0;

  int leftSubtreeHeight = height(p->left);
  int rightSubtreeHeight = height(p->right);

  return (leftSubtreeHeight > rightSubtreeHeight) 
    ? leftSubtreeHeight + 1 
    : rightSubtreeHeight + 1;
 }
    
