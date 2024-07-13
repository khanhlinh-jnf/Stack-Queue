#include "recursive_queue.h"

#include <iostream>
using namespace std;

template <typename T>
void QueueRecursive<T>::init(unsigned int queueSize) {
  if (queueSize <= 0) {
    cout << "Queue size must be positive." << endl;
    return;
  }

  items = new T[queueSize];
  front = -1;
  rear = -1;
  count = 0;
  maxSize = queueSize;
}

template <typename T>
void QueueRecursive<T>::copyQueue(const QueueRecursive<T>& q) {
  if (q.isEmpty()) {
    cout << "Queue is empty. Cannot copy." << endl;
    return;
  }

  init(q.maxSize);

  copyQueueRecursive(q, 0);
}

template <typename T>
void QueueRecursive<T>::copyQueueRecursive(const QueueRecursive<T>& q,
                                           int index) {
  if (index >= q.count) return;
  enqueue(q.items[index]);
  copyQueueRecursive(q, index + 1);
}

template <typename T>
void QueueRecursive<T>::release() {
  if (maxSize == 0) return;
  delete[] items;
  front = -1;
  rear = -1;
  count = 0;
  maxSize = 0;
}

template <typename T>
bool QueueRecursive<T>::isEmpty() const {
  if (front == -1) return true;
  return false;
}

template <typename T>
bool QueueRecursive<T>::isFull() const {
  if (count == maxSize) return true;
  return false;
}

template <typename T>
void QueueRecursive<T>::enqueue(T newItem) {
  if (isFull()) {
    cout << "Queue is full. Cannot enqueue." << endl;
    return;
  }

  if (isEmpty()) {
    front = 0;
  }

  if (front != 0 && rear == maxSize - 1) {
    for (int i = front; i <= rear; i++) {
      items[i - front] = items[i];
    }
    rear = rear - front;
    front = 0;
  }

  count++;
  rear++;
  items[rear] = newItem;
}

template <typename T>
T QueueRecursive<T>::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot dequeue." << endl;
    return -1;
  }

  T item = items[front];
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front++;
  }
  count--;
  return item;
}

template <typename T>
T QueueRecursive<T>::frontValue() const {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot get front value." << endl;
    return -1;
  }

  return items[front];
}

template <typename T>
void QueueRecursive<T>::print() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot print." << endl;
    return;
  }

  for (int i = front; i <= rear; i++) {
    cout << items[i] << " ";
  }
  cout << endl;
}

template <typename T>
void QueueRecursive<T>::printRecursive(int index) {
  if (index > rear) {
    cout << endl;
    return;
  }
  cout << items[index] << " ";
  printRecursive(index + 1);
}

