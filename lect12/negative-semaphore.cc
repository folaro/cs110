/**
 * Shows that a semaphore can be initialized to a negative number
 * which means that there must be -n signals before it can stop
 * waiting.
 */

#include <mutex>
#include <thread>
#include <iostream>
#include "ostreamlock.h"
#include "random-generator.h"
#include "semaphore.h"
#include "thread-utils.h"
using namespace std;

void writer(int i, semaphore &s) {
    cout << oslock << "Sending signal " << i << endl << osunlock;
    s.signal();
}

void read_after_ten(semaphore &s) {
    s.wait();
    cout << oslock << "Got enough signals to continue!" << endl << osunlock;
}

int main(int argc, const char *argv[]) {
    semaphore negSemaphore(-9);
    thread readers[10];
    for (size_t i = 0; i < 10; i++) {
        readers[i] = thread(writer, i, ref(negSemaphore));
    }
    thread r(read_after_ten, ref(negSemaphore));
    for (thread &t : readers) t.join();
    r.join();
    return 0;
}
