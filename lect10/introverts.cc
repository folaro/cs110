#include <iostream>
#include <thread>
#include "ostreamlock.h"

using namespace std;
static void recharge(int i) {
    cout << oslock << "I recharge by spending time alone." <<i << endl << osunlock; 
}
int i=0;
static const size_t kNumIntroverts = 6;
int main(int argc, char *argv[]) {
  cout << "Let's hear from " << kNumIntroverts << " introverts." << endl;      
  thread introverts[kNumIntroverts]; // declare array of empty thread handles
  for (thread& introvert: introverts){
     i++;
     introvert = thread(recharge,i);    // move anonymous threads into empty handles
  }
  //for (thread& introvert: introverts)
    // introvert.join();    
  cout << "Everyone's recharged!" << endl;
  return 0;
}

