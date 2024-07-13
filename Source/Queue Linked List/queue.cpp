#include "queue.h"

#include <iostream>
using namespace std;

template <typename T>
void Queue<T>::init() {
  front = nullptr;
  rear = nullptr;
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T>& q) {
  if (q.isEmpty()) {
    cout << "Queue is empty. Cannot copy." << endl;
    return;
  }
  init();
  Node* current = q.front;
  while (current) {
    enqueue(current->data);
    current = current->next;
  }
}

template <typename T>
void Queue<T>::release() {
  while (front) {
    Node* temp = front;
    front = front->next;
    delete temp;
  }
  rear = nullptr;
}

template <typename T>
bool Queue<T>::isEmpty() const {
  if (front == nullptr) return true;
  return false;
}

template <typename T>
void Queue<T>::enqueue(T newItem) {
  Node* newNode = new Node{newItem, nullptr};

  if (isEmpty()) {
    front = newNode;
  } else {
    rear->next = newNode;
  }
  rear = newNode;
}

template <typename T>
T Queue<T>::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot dequeue." << endl;
    return T();
  }

  Node* temp = front;
  T value = front->data;
  front = front->next;
  delete temp;
  if (front == nullptr) rear = nullptr;
  return value;
}

template <typename T>
T Queue<T>::frontValue() const {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot get front value." << endl;
    return T();
  }
  return front->data;
}

template <typename T>
void Queue<T>::print() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot print." << endl;
    return;
  }

  Node* current = front;
  while (current) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void printMenu() {
  cout << "1. Enqueue" << endl;
  cout << "2. Dequeue" << endl;
  cout << "3. Front value" << endl;
  cout << "4. Copy value" << endl;
  cout << "5. Print" << endl;
  cout << "6. Release queue" << endl;
  cout << "7. Exit" << endl;
}