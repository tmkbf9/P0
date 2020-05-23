.PHONY: clean compile test

GCC := g++
CFLAGS := -g
RM := rm

.cpp.o:
	$(GCC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	$(RM) -f P0
	$(RM) -f traversal_test test_validation test_level_order inOrderTest node_test
	$(RM) -f *.o
	$(RM) -f *~

all: P0 test

P0: buildTree.o traversals.o main.o validation.o
	$(GCC) -o $@ $^

test: traversal_test node_test inOrderTest test_level_order test_validation

traversal_test: traversal_test.o buildTree.o traversals.o
	$(GCC) -o $@ $^
	./traversal_test

node_test: node_test.o buildTree.o traversals.o
	$(GCC) -o $@ $^
	./node_test

inOrderTest: inOrderTest.o buildTree.o traversals.o
	$(GCC) -o $@ $^
	./inOrderTest

test_level_order: test_level_order.o buildTree.o traversals.o
	$(GCC) -o $@ $^
	./test_level_order

test_validation: test_validation.o validation.o
	$(GCC) -o $@ $^
	./test_validation
