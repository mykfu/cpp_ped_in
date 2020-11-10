#include<iostream>
#include <time.h>
#include <limits>
using namespace std;

int* generateArray(int length) {
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}

	return arr;
}

void printArray(int* arr, int length) {		// процедура
	cout << "[";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << (i < length - 1 ? ", " : "");
	}
	cout << "]\n";
}
	
int* getTwoMins(int* arr, int length) {
	if (length < 3) {
		cerr << "Array length must be > 2.\n";
		exit(EXIT_FAILURE);
	}
	int min1 = numeric_limits<int>::max(); 
	int min2 = numeric_limits<int>::max();

	// 1, 3, 2 => 1, 2
	for (int i = 1; i < length; i++)
	{
		// arr_0 = 1 => min1 = 1
		if (arr[i] < min1) {
			min2 = min1;
			min1 = arr[i];
		}
		else if (arr[i] < min2) {
			min2 = arr[i];
		}
	}

	return new int[] {min1, min2};
}

int getSecondLargest(int* arr, int length) {
	return -1;
}

int getMaxSumOfNeighbours(int* arr, int length) {
	return -1;
}

int main() {
	srand(time(0));
	int length = 10;
	int* arr = generateArray(length);
	printArray(arr, length);
	printArray(getTwoMins(arr, length), 2);





}