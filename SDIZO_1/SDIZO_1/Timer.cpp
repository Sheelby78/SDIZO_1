#include "Timer.h"
#include <iostream>

using namespace std;

void Timer::start() {
	startTime = high_resolution_clock::now();
}

void Timer::stop() {
	endTime = high_resolution_clock::now();
}

long Timer::timeCount() {
	return duration_cast<nanoseconds>(endTime - startTime).count();
}