#include <chrono>
#include <ctime>
using namespace std::chrono;

#include "recursive_stack.h"
#include "stack.h"
#define MAX 10000
#define MIN 0

int main() {
  Stack<int> stack, copy;
  StackRecursive<int> stackR, copyR;

  for (int i = 0; i < 5; i++) {
    cout << "Try " << i + 1 << ": " << endl;
    stack.init();
    stackR.init();

    for (int i = 0; i < MAX; i++) {
      int item = rand() % (MAX - MIN + 1) + MIN;
      stack.push(item);
      stackR.push(item);
    }

    auto start = high_resolution_clock::now();
    copy.copyStack(stack);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to copy stack using for loop: " << duration.count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyR.copyStack(stackR);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to copy stack using recursion: " << duration.count()
         << " microseconds" << endl;


    start = high_resolution_clock::now();
    stack.release();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to release stack using for loop: " << duration.count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    stackR.release();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to release stack using recursion: " << duration.count()
         << " microseconds" << endl;

    copy.release();
    copyR.release();
  }

  return 0;
}