#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;
class semaphore {
public:
  semaphore(int value = 0) : value(value) {}
  void signal(); /* value++ */
  void wait();   /* value--, potentially blocking */
private:
  int value;  /* the number of available resource instances */
  std::mutex m;
  std::condition_variable_any cv;

  semaphore(const semaphore& orig) = delete;
  const semaphore& operator=(const semaphore& rhs) const = delete;
};
