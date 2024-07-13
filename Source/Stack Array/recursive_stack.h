#pragma once

template <typename T>
struct StackRecursive {
  T* items;
  int top;
  unsigned int maxSize;

  void init(unsigned int stackSize);
  void copyStack(const StackRecursive<T>& s);
  void copyStackRecursive(const StackRecursive<T>& s, int index);

  void release();

  bool isEmpty() const;
  bool isFull();
  void push(T newItem);
  T pop();
  T topValue();
  void print();
  void printRecursive(int index);
};

#include "recursive_stack.cpp"
