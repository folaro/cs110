#ifndef THREAD_UTILS_H
#define  THREAD_UTILS_H

#include <thread>
#include <chrono>

void sleep_for(const long int t){
const std::chrono::milliseconds  s(t);
	std::this_thread::sleep_for(s);
}
#endif
