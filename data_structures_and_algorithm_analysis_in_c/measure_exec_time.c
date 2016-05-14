//
// Measure ececution time of c program
//
// 1. clock_t
// 
#include "measure_exec_time.h"

clock_t current_time() {
	return clock();
}

double elapsed(clock_t start) {
	clock_t stop = current_time();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	return elapsed;
}
