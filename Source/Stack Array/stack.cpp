#include "stack.h"

#include <iostream>
using namespace std;

template <typename T>
void Stack<T>::init(unsigned int stackSize) {
  if (stackSize <= 0) {
    cout << "Stack size must be positive." << endl;
    return;
  }
  items = new T[stackSize];
  maxSize = stackSize;
  top = -1;
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& s) {
  if (s.isEmpty()) {
    cout << "Stack is empty. Cannot copy." << endl;
    return;
  }
  init(s.maxSize);
  for (int i = 0; i <= s.top; i++) {
    push(s.items[i]);
  }
}

template <typename T>
void Stack<T>::release() {
  if (maxSize == 0) return;
  top = -1;
  maxSize = 0;
  delete[] items;
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
  return top == maxSize - 1;
}

template <typename T>
void Stack<T>::push(T newItem) {
  if (isFull()) {
    cout << "Stack is full. Cannot push." << endl;
    return;
  }
  top++;
  items[top] = newItem;
}

template <typename T>
T Stack<T>::pop() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot pop" << endl;
    return -1;
  }
  top--;
  return items[top + 1];
}

template <typename T>
T Stack<T>::topValue() {
  if (isEmpty()) {
    cout << "Stack is empty. Cannot peek." << endl;
    return -1;
  }
  return items[top];
}

template <typename T>
void Stack<T>::print() {
  if (isEmpty()) {
    cout << "Stack is empty." << endl;
    return;
  }
  for (int i = 0; i <= top; i++) {
    cout << items[i] << " ";
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
