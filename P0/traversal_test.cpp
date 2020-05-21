#include <assert.h>
#include <sstream>

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
  assert(output == "1 a apple\n");
}

int main(int argc, char ** argv) {
  test_traversing_in_order_empty_tree_should_output_nothing();
  test_traversing_in_order_root_should_output_root_data();

  exit(0);
}
