#include <chrono>
#include <ctime>
using namespace std::chrono;

#include "recursive_queue.h"
#include "queue.h"
#define MAX 10000
#define MIN 0

int main() {
  Queue<int> queue, copy;
  QueueRecursive<int> queueR, copyR;

  for (int i = 0; i < 5; i++) {
    cout << "Try " << i + 1 << ": " << endl;
    queue.init(MAX);
    queueR.init(MAX);

    for (int i = 0; i < MAX; i++) {
      int item = rand() % (MAX - MIN + 1) + MIN;
      queue.enqueue(item);
      queueR.enqueue(item);
    }

    auto start = high_resolution_clock::now();
    copy.copyQueue(queue);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time to copy queue using for loop: " << duration.count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    copyR.copyQueue(queueR);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time to copy queue using recursion: " << duration.count()
         << " microseconds" << endl;

    queue.release();
    queueR.release();
    copy.release();
    copyR.release();
  }

  return 0;
}