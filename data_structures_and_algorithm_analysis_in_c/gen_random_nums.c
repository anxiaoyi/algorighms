//
// Generate random numbers, and save them to a file
//
// 1. Open file
//    w+: Creates a empty file for both reading and writing
//
// 2. Generate random numbers
//    The C library function int rand(void) returns a pseudo-random number in the range of 0 to RAND_MAX.
//
// 3. main function receive arguments
//    `gcc mysort.c -o mysort`
//    `mysort 2 8 9 1 4 5`
//    
//    Assue main function declaration: 
//    `int main(argc, char *argv[])`
//    
//    Argument Count: argc = 7
//    Argument Vector: argv = { "mysort", "2", "8", "9", "1", "4", "5" }
//
// 4. atoi
// 5. The C library function int fprintf(FILE *stream, const char *format, ...) sends formatted output to a stream.
//
// 2016.05.13
//

#define FILE_NAME "random_nums.data"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	FILE *fp;
	fp = fopen(FILE_NAME, "w+");

	time_t t;
	srand((unsigned) time(&t));

	int n = atoi(argv[1]);
	int i;

	printf("=====gen %d nums=====\n", n);

	for (i=0; i<n; ++i) {
		fprintf(fp, "%d\n", rand() % n);
	}

	fclose(fp);

	return 0;
}
