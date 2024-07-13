#include "recursive_stack.h"

#include <iostream>
using namespace std;

template <typename T>
void StackRecursive<T>::init(unsigned int stackSize) {
  if (stackSize <= 0) {
    cout << "Stack size must be positive." << endl;
    return;
  }
  items = new T[stackSize];
  maxSize = stackSize;
  top = -1;
}

template <typename T>
void StackRecursive<T>::copyStack(const StackRecursive<T>& s) {
  if (s.isEmpty()) {
    cout << "Stack is empty. Cannot copy." << endl;
    return;
  }
  init(s.maxSize);
  copyStackRecursive(s, s.top);
}

template <typename T>
void StackRecursive<T>::copyStackRecursive(const StackRecursive<T>& s,
                                           int index) {
  if (index < 0) return;

  copyStackRecursive(s, index - 1);
  push(s.items[index]);
}

template <typename T>
void StackRecursive<T>::release() {
  if (maxSize == 0) return;
  top = -1;
  maxSize = 0;
  delete[] items;
}

template <typename T>
bool StackRecursive<T>::isEmpty() const {
  return top == -1;
}

template <typename T>
bool StackRecursive<T>::isFull() {
  return top == maxSize - 1;
}

template <typename T>
void StackRecursive<T>::push(T newItem) {
  if (isFull()) {
    cout << "Stack is full. Cannot push." << endl;
    return;
  }
  top++;
  items[top] = newItem;
}

template <typename T>
T StackRecursive<T>::pop() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot pop" << endl;
    return -1;
  }
  top--;
  return items[top + 1];
}

template <typename T>
T StackRecursive<T>::topValue() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot peek." << endl;
    return -1;
  }
  return items[top];
}

template <typename T>
void StackRecursive<T>::print() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return;
  }
  printRecursive(top);
  cout << endl;
}

template <typename T>
void StackRecursive<T>::printRecursive(int index) {
  if (index < 0) {
    return;
  }

  printRecursive(index - 1);
  cout << items[index] << " ";
}