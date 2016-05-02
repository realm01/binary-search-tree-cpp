#include <iostream>
#include <ctime>
#include <cstdlib>
#include "bst.h"

using namespace std;

int main() {
  srand((unsigned)time(NULL));

  const int size = 1000000;
  int* arr = new int[size];

  for(int i = 0; i < size; i++)
    arr[i] = rand() % 1000000 + 1;

  BST<int>* ex = new BST<int>(arr, size);

  ex->dump();

  cout << ex->search(2) << endl;
  cout << ex->search(5) << endl;

  ex->del(7);
  ex->dump();

  return 0;
}
