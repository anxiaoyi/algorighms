//
// Select kth largest number from N numbers
//
// 1. How to define array in C
// 2. Bubble sort implementation
// 3. How to run a c program 
//     3.1 `gcc bubble_sort.c -o myapp`
//     3.2 `./myapp`
// 4. include <stdio.h> because of `printf` function
// 5. compile mutiple c files
//     `gcc measure_exec_time.c 1_1.c -o myapp`
//
// 2016.05.13
// 2016.05.14
//
// Author: Kun Zhao
//

#include <stdio.h>
#include <stdlib.h>
#include "measure_exec_time.h"

void swap(int list[], int i, int j) {
	int temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

// 
// 如果前边的 > 后边的，那么这两个元素交换位置
// 即：大的冒泡到末尾
//
// i: 实质上相当于已经确定位置的元素个数
// j: n-i: 剩下的未确定的元素个数
//
// [5][4][3][2][1]
//
void bubble_sort(int list[], int n) {
	int i, j;
	for (i=0; i<n-1; i++) {
		for(j=0; j<n-1-i; j++) {
			if (list[j] < list[j+1]) {
				swap(list, j, j+1);
			}
		}
	}
}

int* read_arrays(FILE *file, int n) {
	int i=0;
	int *array = (int *)malloc(sizeof(int) * n);
	for (; i<n; i++) {
		fscanf(file, "%d", &array[i]);
	}
	return array;
}

//  
// N: 10, k: 5, time: 0.148ms
// N: 100, k: 50, time: 0.257ms
// N: 1000, k: 500, time: 5.246ms
// N: 10000, k: 5000, time: 222.699ms
// N: 100000, k: 50000, time: 13199.613ms
//
int first_solution(FILE *file, int n, int k) {
	int *array = read_arrays(file, n); 
	bubble_sort(array, n);
	return array[k-1];
}

//
// N: 10, k: 5, time: 0.109ms
// N: 100, k: 50, time: 0.262ms
// N: 1000, k: 500, time: 5.086ms
// N: 10000, k: 5000, time: 203.387ms
// N: 100000, k: 50000, time: 13071.089ms
//
int second_solution(FILE *file, int n, int k) {
	int i=0;
	int *array = (int *)malloc(sizeof(int) * (k + 1));
	while(i<n) {
		int position = i <= k ? i : k;
		fscanf(file, "%d", &array[position]);
		int j = position;
		while( (j-1)>=0 && array[j] > array[j-1] ) {
			swap(array, j, j-1);
			j--;
		}
		i++;
	}
	return array[k - 1];
}

//
// ./myapp file_name 10
// ./myapp `your_file_name` `numbers in this file`
//
int main(int argc, char *argv[]) {
	FILE *file = fopen(argv[1], "r");

	int n = atoi(argv[2]);
	int k = n / 2;
	clock_t start = current_time();

	int kth_num = -1;

//  Comment/UnComment to select different solutions ...

	printf("===FIRST SOLUTION===\n");
	kth_num = first_solution(file, n, k);

//	printf("===SECOND SOLUTION===\n");
//	kth_num = second_solution(file, n, k);

	printf("The [%d]th number is %d.\n", k, kth_num);
	double elapsed_time = elapsed(start);
	printf("Time elpased %f ms\n", elapsed_time);

	fclose(file);

	return 0;
}
