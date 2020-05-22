#include <assert.h>
#include <sstream>
#include <iostream>

#include "node.h"

using namespace std;

void test_traversing_in_order_empty_tree_should_output_nothing() {
  ostringstream logFile;
  
  Node * node = new Node();
  node->traverseInOrder(logFile);

  assert(logFile.str().empty());
}

void test_traversing_in_order_root_should_output_root_data() {
  ostringstream logFile;
  
  Node * node = new Node();
  node->buildTree("apple");
  
  node->traverseInOrder(logFile);

  string output = logFile.str();
  assert(output.empty() == false);
  assert(output == "1 a apple \n");
}

void test_adding_same_node_twice_at_root_displays_strings_in_FIFO_order() {
  ostringstream logFile;
  
  Node * node = new Node();
  node->buildTree("apple");
  node->buildTree("anotherapple");
  
  node->traverseInOrder(logFile);

  string output = logFile.str();
  assert(output.empty() == false);
  assert(output == "1 a apple anotherapple \n");
}  


// void test_traversing_in_order_to_left_should_output_both() {
//   ostringstream logFile;
  
//   Node * node = new Node();
//   node->buildTree("bpple");
//   node->buildTree("apple");
  
//   node->traverseInOrder(logFile);

//   string output = logFile.str();
//   string expectedOutput;
//   expectedOutput << "  " << 2 << " a apple\n
//   assert(output == 
// }


int main(int argc, char ** argv) {
  test_traversing_in_order_empty_tree_should_output_nothing();
  test_traversing_in_order_root_should_output_root_data();
  test_adding_same_node_twice_at_root_displays_strings_in_FIFO_order();

  exit(0);
}
