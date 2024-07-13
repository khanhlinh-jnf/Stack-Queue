#pragma once

template <typename T>
struct QueueRecursive {
  T* items;
  int front;
  int rear;
  unsigned int count;
  unsigned int maxSize;

  void init(unsigned int queueSize);
  void copyQueue(const QueueRecursive<T>& q);
  void copyQueueRecursive(const QueueRecursive<T>& q, int index);
  void release();

  bool isEmpty() const;
  bool isFull() const;

  void enqueue(T newItem);
  T dequeue();
  T frontValue() const;

  void print();
  void printRecursive(int index);
};


#include "recursive_queue.cpp"