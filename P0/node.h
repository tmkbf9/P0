#pragma once
#ifndef P0_NODE_H
#define P0_NODE_H

#include <list>
#include <string>
#include <iosfwd>

struct node {
  char data;
  node* left;
  node* right;
  std::list<std::string> tokens;
  
  node() : left(NULL), right(NULL) {}
};


#endif //P0_NODE_H
