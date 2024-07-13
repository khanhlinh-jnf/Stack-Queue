#pragma once

template <typename T>
struct QueueRecursive {
  
  struct Node {
    T data;
    Node* next;
  };

  Node* front;
  Node* rear;

  void init();
  void copyQueue(const QueueRecursive<T>& q);
  void copyQueueRecursive(Node* current);
  void release(); 
  void releaseRecursive(Node* currrent);

  bool isEmpty() const;
  
  void enqueue(T newItem);
  T dequeue();
  T frontValue() const;

  void print();
  void printRecursive(Node* current);
};

#include "recursive_queue.cpp"