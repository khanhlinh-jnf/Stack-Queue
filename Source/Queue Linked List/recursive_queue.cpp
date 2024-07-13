#include "recursive_queue.h"

#include <iostream>
using namespace std;

template <typename T>
void QueueRecursive<T>::init() {
  front = nullptr;
  rear = nullptr;
}

template <typename T>
void QueueRecursive<T>::copyQueue(const QueueRecursive<T>& q) {
  if (q.isEmpty()) {
    cout << "Queue is empty. Cannot copy." << endl;
    return;
  }
  init();
  Node* current = q.front;
  copyQueueRecursive(current);
}

template <typename T>
void QueueRecursive<T>::copyQueueRecursive(Node* current) {
  if (current == nullptr) return;
  enqueue(current->data);
  copyQueueRecursive(current->next);
}

template <typename T>
void QueueRecursive<T>::release() {
  releaseRecursive(front);
  front = nullptr;
  rear = nullptr;
}

template <typename T>
void QueueRecursive<T>::releaseRecursive(Node* current) {
  if (current == nullptr) {
    return;
  }
  releaseRecursive(current->next);
  delete current;
}

template <typename T>
bool QueueRecursive<T>::isEmpty() const {
  if (front == nullptr) return true;
  return false;
}

template <typename T>
void QueueRecursive<T>::enqueue(T newItem) {
  Node* newNode = new Node{newItem, nullptr};

  if (isEmpty()) {
    front = newNode;
  } else {
    rear->next = newNode;
  }
  rear = newNode;
}

template <typename T>
T QueueRecursive<T>::dequeue() {
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
T QueueRecursive<T>::frontValue() const {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot get front value." << endl;
    return T();
  }
  return front->data;
}

template <typename T>
void QueueRecursive<T>::print() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot print." << endl;
    return;
  }

  Node* current = front;
  printRecursive(current);
}

template <typename T>
void QueueRecursive<T>::printRecursive(Node* current) {
  if (current == nullptr) {
    cout << endl;
    return;
  }
  cout << current->data << " ";
  printRecursive(current->next);
}