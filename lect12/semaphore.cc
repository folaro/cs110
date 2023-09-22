#include "semaphore.h"
#include <mutex>
void semaphore::signal() {
    std::lock_guard<mutex> lg(m); /* m.lock() to protect value */
    value++;

    /* notify cv that value becomes > 0 */
    if (value == 1) cv.notify_all();
} /* lock_guard, as a local, is destructed here and m is unlocked */

void semaphore::wait() {
    std::lock_guard<mutex> lg(m); /* m.lock() to protect value */

    /* make sure value > 0 before proceeding,
       if not, block & wait here */
    cv.wait(m, [this]{return value > 0;});

    value--;
} /* lock_guard, as a local, is destructed here and m is unlocked */
