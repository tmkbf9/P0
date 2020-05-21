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

int main(int argc, char ** argv) {
  test_traversing_in_order_empty_tree_should_output_nothing();
  exit(0);
}
