#include "queue.h"
#include "recursive_queue.h"

int main() {
  Queue<int> queue;
  QueueRecursive<int> queueR;

  int type = 0;
  cout << "Choose the type of implementation (1: For loop, 2: Recursive): ";
  do {
    cin >> type;
    if (type != 1 && type != 2) {
      cout << "Invalid choice. Please try again: ";
    }
  } while (type != 1 && type != 2);

  int choice = 0;
  printMenu();
  if (type == 1) {
    queue.init();
    while (choice != 7) {
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
        case 1:
          int item;
          cout << "Enter the item to enqueue: ";
          cin >> item;
          queue.enqueue(item);
          break;
        case 2:
          if (queue.dequeue() != -1) cout << "Item dequeued" << endl;
          break;
        case 3:
          if (!queue.isEmpty())
            cout << "Front value: " << queue.frontValue() << endl;
          else
            cout << "Queue is empty. Cannot get front value." << endl;
          break;
        case 4:
          Queue<int> copy;
          copy.copyQueue(queue);
          cout << "Copied queue: ";
          copy.print();
          break;
        case 5:
          queue.print();
          break;
        case 6:
          queue.release();
          cout << "Queue released." << endl;
          break;
        case 7:
          queue.release();
          cout << "Queue released." << endl;
          cout << "Exiting..." << endl;
          break;
        default:
          cout << "Invalid choice." << endl;
          break;
      }
    }
  }

  else {
    queueR.init();
    while (choice != 7) {
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
        case 1:
          int item;
          cout << "Enter the item to enqueue: ";
          cin >> item;
          queueR.enqueue(item);
          break;
        case 2:
          if (queueR.dequeue() != -1) cout << "Item dequeued" << endl;
          break;
        case 3:
          if (!queueR.isEmpty())
            cout << "Front value: " << queueR.frontValue() << endl;
          else
            cout << "Queue is empty. Cannot get front value." << endl;
          break;
        case 4:
          QueueRecursive<int> copy;
          copy.copyQueue(queueR);
          cout << "Copied queue: ";
          copy.print();
          break;
        case 5:
          queueR.print();
          break;
        case 6:
          queueR.release();
          cout << "Queue released." << endl;
          break;
        case 7:
          queueR.release();
          cout << "Queue released." << endl;
          cout << "Exiting..." << endl;
          break;
        default:
          cout << "Invalid choice." << endl;
          break;
      }
    }
  }
  return 0;
}
