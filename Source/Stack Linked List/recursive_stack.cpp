#include "recursive_stack.h"

#include <iostream>
using namespace std;

template <typename T>
void StackRecursive<T>::init() {
  top = nullptr;
}


template <typename T>
void StackRecursive<T>::copyStack(const StackRecursive<T>& s) {
  if (s.isEmpty()) {
    cout << "Stack is empty. Cannot copy." << endl;
    return;
  }
  init();
  copyStackRecursive(s.top);
}

template <typename T>
void StackRecursive<T>::copyStackRecursive(Node* current) {
  if (!current) {
    return;
  }
  copyStackRecursive(current->next);
  push(current->data);
}

template <typename T>
void StackRecursive<T>::release() {
  if (isEmpty()) return;
  releaseRecursive(top);
  top = nullptr;
}

template <typename T>
void StackRecursive<T>::releaseRecursive(Node* current) {
  if (!current) {
    return;
  }
  Node* next = current->next;
  delete current;
  releaseRecursive(next);
}

template <typename T>
bool StackRecursive<T>::isEmpty() const {
  return (top == nullptr);
}

template <typename T>
void StackRecursive<T>::push(T newItem) {
  Node* newNode = new Node{newItem, top};
  top = newNode;
}

template <typename T>
T StackRecursive<T>::pop() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot pop." << endl;
    return -1;
  }
  Node* temp = top;
  top = top->next;
  T value = temp->data;
  delete temp;
  return value;
}

template <typename T>
T StackRecursive<T>::topValue() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot peek." << endl;
    return -1;
  }
  return top->data;
}

template <typename T>
void StackRecursive<T>::print() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return;
  }
  Node* current = top;
  while (current) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

template <typename T>
void StackRecursive<T>::printRecursive(Node* current) {
  if (!current) {
    return;
  }
  printRecursive(current->next);
  cout << current->data << " ";
}

// template <typename T>
// void Stack<T>::print() {
//   if (isEmpty()) {
//     cout << "Stack is empty." << endl;
//     return;
//   }
//   Node* current = top;
//   Stack<T> temp;
//   while (current) {
//     temp.push(current->data);
//     current = current->next;
//   }
//   while (!temp.isEmpty()) {
//     cout << temp.pop() << " ";
//   }
//   cout << endl;
// }
