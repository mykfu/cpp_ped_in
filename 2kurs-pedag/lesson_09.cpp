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

bool in_array(int* arr, int length, int findMe) { // O(n)
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == findMe) {
			return true;
		}
	}
	return false;
}

bool binary_search(int* sorted, int length, int findMe) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (sorted[middle] < findMe) {
			left = middle + 1;
		}
		else if (sorted[middle] > findMe) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}
	return false;
}

// left < right => strcmp(left, right) = -1
// left == right => strcmp(left, right) = 0
// left > right => strcmp(left, right) = 1
// ее, еее
// стол, блок 
// 241, 225
int compare(string left, string right) {
	int len = min(left.length(), right.length());

	for (int i = 0; i < len; i++)
	{
		int c1 = ((unsigned char) left.at(i)) * 2;
		int c2 = ((unsigned char) right.at(i)) * 2;


		if (left.at(i) == 'ё') c1 = ((unsigned char)'е') * 2 + 1;
		if (right.at(i) == 'ё') c2 = ((unsigned char)'е') * 2 + 1;

		if (c1 != c2) {
			return c1 - c2;
		}
	}
	return left.length() - right.length();
}

bool binary_search(string* sorted, int length, string findMe) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (compare(sorted[middle], findMe) < 0) {
			left = middle + 1;
		}
		else if (compare(sorted[middle], findMe) > 0) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}
	return false;
}


int main2() {
	setlocale(LC_ALL, "ru");

	//srand(time(0));
	int length = 10;
	int* arr = generateArray(length);
	cout << "printArray:\n\t";
	printArray(arr, length);

	cout << "getTwoMins:\n\t";
	printArray(getTwoMins(arr, length), 2);

	cout << "in_array 12:\n\t";
	cout << (in_array(arr, length, 12) ? "Found" : "Not found") << endl;
	cout << "in_array 69:\n\t";
	cout << (in_array(arr, length, 69) ? "Found" : "Not found") << endl;

	// findMe = 97
	// middle = 42
	// 42 ? 97
	// 69, 73, 87, 93, 97
	// 87 ? 97
	// 93, 97
	// 93 ? 97
	// 97
	// 97 ? 97
	// found
	int* sorted = new int[length] {2, 4, 8, 23, 42, 69, 73, 87, 93, 97};

	cout << "printArray:\n\t";
	printArray(sorted, length);
	cout << "binary_search 12:\n\t";
	cout << (binary_search(sorted, length, 12) ? "Found" : "Not found") << endl;
	cout << "binary_search 69:\n\t";
	cout << (binary_search(sorted, length, 69) ? "Found" : "Not found") << endl;

	string* strs = new string[] {"ее", "ель", "ёж", "неуд", "слон", "стол"};

	cout << "binary_search ёж:\n\t";
	cout << (binary_search(strs, 6, "ёж") ? "Found" : "Not found") << endl;



	cout << compare("ёлка", "ель") << endl;
	cout << compare("стол", "блок") << endl;
	cout << compare("сто", "стол") << endl;


	return 0;
}