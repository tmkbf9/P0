#include <assert.h>

#include "buildTree.h"
#include "node.h"

void test_adding_root_node_to_tree() {
  Node * node = new Node();
  
  node->buildTree("a");

  assert(node->getRoot()->data == 'a');
  assert(node->getRoot()->left == NULL);
  assert(node->getRoot()->right == NULL);
  assert(node->getRoot()->tokens.front() == "a");
}

void test_adding_lesser_node_to_tree_adds_node_to_left() {
  Node * node = new Node();
  
  node->buildTree("b");
  node->buildTree("a");

  assert(node->getRoot()->data == 'b');
  assert(node->getRoot()->left != NULL);
  assert(node->getRoot()->left->data == 'a');
  assert(node->getRoot()->left->left == NULL);
  assert(node->getRoot()->left->right == NULL);
  assert(node->getRoot()->right == NULL);
  assert(node->getRoot()->left->tokens.front() == "a");
}

void test_adding_greater_node_to_tree_adds_node_to_right() {
  Node * node = new Node();
  
  node->buildTree("b");
  node->buildTree("c");

  assert(node->getRoot()->data == 'b');
  assert(node->getRoot()->left == NULL);
  assert(node->getRoot()->right->data == 'c');
  assert(node->getRoot()->right->left == NULL);
  assert(node->getRoot()->right->right == NULL);
  assert(node->getRoot()->right->tokens.front() == "c");
}

void test_adding_second_node_with_same_first_letter_only_adds_token_to_list() {
  Node * node = new Node();

  node->buildTree("bob");
  node->buildTree("brian");

  assert(node->getRoot()->tokens.size() == 2);
  assert(node->getRoot()->tokens.front() == "bob");
  node->getRoot()->tokens.pop_front();
  assert(node->getRoot()->tokens.front() == "brian");
}

void test_adding_second_interior_node_with_same_first_letter() {
  Node * node = new Node();
  node->buildTree("middle");
  node->buildTree("alpha");

  node->buildTree("apple");

  assert(node->getRoot()->left->tokens.size() == 2);
  assert(node->getRoot()->left->tokens.front() == "alpha");
  node->getRoot()->left->tokens.pop_front();
  assert(node->getRoot()->left->tokens.front() == "apple");
}

int main(int argc, char ** argv) {
  test_adding_root_node_to_tree();
  test_adding_lesser_node_to_tree_adds_node_to_left();
  test_adding_greater_node_to_tree_adds_node_to_right();
  test_adding_second_node_with_same_first_letter_only_adds_token_to_list();
  test_adding_second_interior_node_with_same_first_letter();
}
