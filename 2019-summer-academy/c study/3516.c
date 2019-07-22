#include "test.h"
#if (PNUM == 3516)
//선택정렬
#include <stdio.h>
int data[] = { 2, 1, 9, 7, -3, 2, 6, 4, 3, 8 };
int N;
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//XOR 성질이용
void swap2(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void simpleSort(int N)
{
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (data[i] > data[j]) {
				//temp = data[i];
				//data[i] = data[j];
				//data[j] = temp;
				swap(&data[i], &data[j]);
			}
		}
	}
}
void simpleSort2(int N)
{
	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (data[i] < data[j]) {
				swap2(&data[i], &data[j]);
			}
		}
	}
}
void printAry(int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}
void main(void)
{
	int N = sizeof(data) / sizeof(data[0]);
	printAry(N);
	simpleSort(N);
	printAry(N);
	simpleSort2(N);
	printAry(N);
}
#endif