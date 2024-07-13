#include "queue.h"

#include <iostream>
using namespace std;

template <typename T>
void Queue<T>::init(unsigned int queueSize) {
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
void Queue<T>::copyQueue(const Queue<T>& q) {
  if (q.isEmpty()) {
    cout << "Queue is empty. Cannot copy." << endl;
    return;
  }

  init(q.maxSize);

  for (int i = 0; i < q.count; i++) {
    enqueue(q.items[i]);
  }
}

template <typename T>
void Queue<T>::release() {
  if (maxSize == 0) return;
  delete[] items;
  front = -1;
  rear = -1;
  count = 0;
  maxSize = 0;
}

template <typename T>
bool Queue<T>::isEmpty() const {
  if (front == -1) return true;
  return false;
}

template <typename T>
bool Queue<T>::isFull() const {
  if (count == maxSize) return true;
  return false;
}

template <typename T>
void Queue<T>::enqueue(T newItem) {
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
T Queue<T>::dequeue() {
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
T Queue<T>::frontValue() const {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot get front value." << endl;
    return -1;
  }

  return items[front];
}

template <typename T>
void Queue<T>::print() {
  if (isEmpty()) {
    cout << "Queue is empty. Cannot print." << endl;
    return;
  }

  for (int i = front; i <= rear; i++) {
    cout << items[i] << " ";
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