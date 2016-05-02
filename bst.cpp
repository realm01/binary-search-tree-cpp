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

template <typename T>
BST<T>::BST(const T* arr, const unsigned int& size) {
  first = NULL;
  if(arr != NULL) {
    convertFrom(arr, size);
  }
}

template <typename T>
BST<T>::BST::Node::Node(const T& item) {
  left = NULL;
  right = NULL;
  this->item = item;
}

template <typename T>
typename BST<T>::BST::Node** BST<T>::search_node(const T& item) {
  Node** curr_node = &first;

  while(true) {
    if(*curr_node == NULL) {
      return NULL;
    }else{
      if(item == (*curr_node)->item) {
        return curr_node;
      }else{
        if((*curr_node)->left != NULL && item <= (*curr_node)->item) {
          curr_node = &((*curr_node)->left);
        }else if((*curr_node)->right != NULL && item >= (*curr_node)->item) {
          curr_node = &((*curr_node)->right);
        }else{
          return NULL;
        }
      }
    }
  }
}

template <typename T>
T* BST<T>::search(const T& item) {
  Node** tmp = search_node(item);

  if(tmp == NULL)
    return NULL;
  else
    return &((*tmp)->item);
}

template <typename T>
void BST<T>::insert(const T& item, Node** next) {
  Node** curr_node = NULL;

  if(next != NULL)
    curr_node = next;

  if(curr_node == NULL)
    curr_node = &first;

  if(*curr_node == NULL) {
    *curr_node = new Node(item);
  }else{
    if(item < (*curr_node)->item) {
      insert(item, &((*curr_node)->left));
    }else if(item > (*curr_node)->item) {
      insert(item, &((*curr_node)->right));
    }
  }
}

template <typename T>
void BST<T>::del(const T& item) {
  Node** to_del_node = search_node(item);

  if(to_del_node == NULL)
    return void();

  if((*to_del_node)->left == NULL && (*to_del_node)->right == NULL) {
    delete(*to_del_node);
    *to_del_node = NULL;
  }else if((*to_del_node)->left == NULL && (*to_del_node)->right != NULL) {
    (*to_del_node)->item = (*to_del_node)->right->item;
    (*to_del_node)->left = (*to_del_node)->right->left;
    (*to_del_node)->right = (*to_del_node)->right->right;
  }else if((*to_del_node)->left != NULL && (*to_del_node)->right == NULL) {
    (*to_del_node)->item = (*to_del_node)->left->item;
    (*to_del_node)->right = (*to_del_node)->left->right;
    (*to_del_node)->left = (*to_del_node)->left->left;
  }else{
    Node** curr_node = &((*to_del_node)->left);

    if((*curr_node)->right == NULL && (*curr_node)->left == NULL) {
      (*to_del_node)->item = (*curr_node)->item;
      delete(*curr_node);
      *curr_node = NULL;
      return void();
    }

    if((*curr_node)->right == NULL) {
      (*to_del_node)->item = (*curr_node)->item;
      (*to_del_node)->left = (*curr_node)->left;
      return void();
    }

    while(true) {
    if((*curr_node)->right->right == NULL) {
        break;
      }else{
        curr_node = &((*curr_node)->right);
      }
    }

    if((*curr_node)->right == NULL && (*curr_node)->left == NULL) {
      (*to_del_node)->item = (*curr_node)->item;
      delete(*curr_node);
    }else{
      (*to_del_node)->item = (*curr_node)->right->item;
      (*curr_node)->right = (*curr_node)->right->left;
    }
  }
}

template <typename T>
void BST<T>::convertFrom(const T* arr, const unsigned int& size) {
  for(unsigned int i = 0; i < size; i++) {
    insert(arr[i]);
  }
}

template <typename T>
void BST<T>::dump(Node const * next) {
  Node const * curr_node = next;
  if(curr_node == NULL)
    curr_node = first;

  std::cout << "|" << curr_node->item;
  if(curr_node->left != NULL) {
    dump(curr_node->left);
  }

  if(curr_node->right != NULL) {
    dump(curr_node->right);
  }

  if(next == NULL)
    std::cout << "|" << std::endl;
}
