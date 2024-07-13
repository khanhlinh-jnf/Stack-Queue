#pragma once

template <typename T>
struct StackRecursive {
  struct Node {
    T data;
    Node* next;
  };

  Node* top;

  void init();
  void copyStack(const StackRecursive<T>& s);
  void copyStackRecursive(Node* current);
   void release();
  void releaseRecursive(Node* current);

  bool isEmpty() const;

  void push(T newItem);
  T pop();
  T topValue();
  void print();
  void printRecursive(Node* current);
};

#include "recursive_stack.cpp"
