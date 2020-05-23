#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <queue>

#include "node.h"
#include "buildTree.h"

using namespace std;

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

node* Node::createNewNode(const string& word) {
    node* t = new node();

    t->data = word.at(0);
    t->left = NULL;
    t->right = NULL;
    t->tokens.push_back(word);

    return t;
}
