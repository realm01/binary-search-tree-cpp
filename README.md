Binary Search Tree
==================
Usage
-----
Please refer to the `main.cpp` but here are the methods listed you can use on this class:
```c++
// Takes 2 or 0 parameter
// you can give it an array which will be converted into a BST Tree
BST<int>* bst = new BST<int>(arr, size);

bst->search(2);       // searches for an element, returns a pointer to the element if it exists
                      // and a NULL pointer if it doesnt exists
bst->insert(74353);   // inserts a single element into the tree, returns void
bst->del(2);          // delete a specific element in the tree, returns void
bst->dump();          // prints all elements, returns void

// converrFrom takes an array and pushes it into the BST
int test_arr[2] = {1, 2};
bst->convertFrom(test_arr, 2);    // returns void
```
