#pragma once

template <typename T>
struct Queue {
  
  struct Node {
    T data;
    Node* next;
  };

  Node* front;
  Node* rear;

  void init();
  void copyQueue(const Queue<T>& q);
  void release();

  bool isEmpty() const;
  
  void enqueue(T newItem);
  T dequeue();
  T frontValue() const;

  void print();
};

void printMenu();
#include "queue.cpp"