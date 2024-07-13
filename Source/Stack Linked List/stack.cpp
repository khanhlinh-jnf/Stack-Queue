#include "stack.h"

#include <iostream>

using namespace std;

template <typename T>
void Stack<T>::init() {
  top = nullptr;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
  if (s.isEmpty()) {
    cout << "Stack is empty. Cannot copy." << endl;
    return;
  }
  init();
  Node* current = s.top;

  while (current) {
    push(current->data);
    current = current->next;
  }

  //reverse
  Node* prev = nullptr;
  current = top;
  Node* next = nullptr;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  top = prev;
}

template <typename T>
void Stack<T>::release() {
  if (isEmpty()) return;
  Node* current = top;
  while (current) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  top = nullptr;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return (top == nullptr);
}

template <typename T>
void Stack<T>::push(T newItem) {
  Node* newNode = new Node{newItem, top};
  top = newNode;
}

template <typename T>
T Stack<T>::pop() {
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
T Stack<T>::topValue() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot peek." << endl;
    return -1;
  }
  return top->data;
}

template <typename T>
void Stack<T>::print() {
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

void printMenu() {
  cout << "1. Push item" << endl;
  cout << "2. Pop item" << endl;
  cout << "3. Get the value of top item" << endl;
  cout << "4. Copy stack" << endl;
  cout << "5. Print stack" << endl;
  cout << "6. Release stack" << endl;
  cout << "7. Exit" << endl;
}
