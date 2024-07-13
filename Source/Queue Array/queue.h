#pragma once

template <typename T>
struct Queue {
  T* items;
  int front;
  int rear;
  unsigned int count;
  unsigned int maxSize;

  void init(unsigned int queueSize);
  void copyQueue(const Queue<T>& q);
  void release();

  bool isEmpty() const;
  bool isFull() const;

  void enqueue(T newItem);
  T dequeue();
  T frontValue() const;

  void print();
};

void printMenu();
#include "queue.cpp"