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

#ifndef __BST_H
#define __BST_H

template <typename T>
class BST {
  private:
    class Node {
      friend class BST;
      private:
        T item;
        Node* left;
        Node* right;
      public:
        Node(const T& item);
    };
    Node* first;
    Node** search_node(const T& item);
  public:
    BST(const T* arr = NULL, const unsigned int& size = 0);
    T* search(const T& item);
    void insert(const T& item, Node** next = NULL);
    void del(const T& item);
    void convertFrom(const T* arr, const unsigned int& size);
    void dump(const Node* next = NULL);
};

#include "bst.cpp"

#endif
