#include<iostream>
using namespace std;

void swap(int& a, int& b);
//{
//	int t = a;
//	a = b;
//	b = t;
//}

void bubbleSort(int*& arr, int length) {
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void partition(int* a, int left, int right) {
	for (int i = left; i < right; i++)
	{

	}
}

void quickSort(int*& arr, int left, int right) {
	int pivot_ind = left + (right - left) / 2;

	if (left < right) {

		quickSort(arr, left, pivot_ind - 1);
		quickSort(arr, pivot_ind + 1, right);
	}

}

void quickSort(int*& arr, int length) {
	quickSort(arr, 0, length - 1);
}

int main() {

	int length = 10;
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;
	bubbleSort(arr, length);
	
	for (int i = 0; i < length; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;






}