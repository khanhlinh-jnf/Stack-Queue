#include "recursive_stack.h"
#include "stack.h"

int main() {
  Stack<int> stack;
  StackRecursive<int> stackR;

  stack.init();
  stackR.init();

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
    while (choice != 7) {
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
        case 1: {
          int item;
          cout << "Enter the item to push: ";
          cin >> item;
          stack.push(item);
          break;
        }
        case 2: {
          if (stack.pop() != -1) {
            cout << "Item popped." << endl;
          }
          break;
        }
        case 3: {
          if (!stack.isEmpty()) {
            cout << "Top value: " << stack.topValue() << endl;
          } else {
            cout << "Stack is empty." << endl;
          }
          break;
        }
        case 4: {
          Stack<int> copy;
          copy.copyStack(stack);
          cout << "Copied stack:" << endl;
          copy.print();
          copy.release();
          break;
        }
        case 5: {
          stack.print();
          break;
        }
        case 6: {
          stack.release();
          cout << "Stack released." << endl;
          break;
        }
        case 7: {
          stack.release();
          cout << "Stack released." << endl;
          cout << "Exiting..." << endl;
          break;
        }
        default: {
          cout << "Invalid choice. Please try again." << endl;
          break;
        }
      }
    }
  } else {
    while (choice != 7) {
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
        case 1: {
          int item;
          cout << "Enter the item to push: ";
          cin >> item;
          stackR.push(item);
          break;
        }
        case 2: {
          if (stackR.pop() != -1) {
            cout << "Item popped." << endl;
          }
          break;
        }
        case 3: {
          if (!stackR.isEmpty()) {
            cout << "Top value: " << stackR.topValue() << endl;
          } else {
            cout << "Stack is empty." << endl;
          }
          break;
        }
        case 4: {
          StackRecursive<int> copy;
          copy.copyStack(stackR);
          cout << "Copied stack:" << endl;
          copy.print();
          copy.release();
          break;
        }
        case 5: {
          stackR.print();
          break;
        }
        case 6: {
          stackR.release();
          cout << "Stack released." << endl;
          break;
        }
        case 7: {
          stackR.release();
          cout << "Stack released." << endl;
          cout << "Exiting..." << endl;
          break;
        }
        default: {
          cout << "Invalid choice. Please try again." << endl;
          break;
        }
      }
    }
  }

  return 0;
}
