/*
* Created by: Anastassios Martakos
*
* Copyright 2016 Anastassios Martakos
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*/

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

  //ex->dump();

  cout << ex->search(2) << endl;
  cout << ex->search(5) << endl;

  ex->del(7);
  //ex->dump();

  delete arr;
  delete ex;

  return 0;
}
