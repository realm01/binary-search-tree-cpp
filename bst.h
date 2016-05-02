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
