#include<iostream>
using namespace std;


void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
}

void swap2(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void swap(int* a, int* b) {
	int t = *a;
	a = b;
	b = &t;
}

void lesson_05() {
	int x = 5;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;

	int* p = &x;

	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	const int n = 10;
	int m = 10;
	int ints[n];

	int* ptrInts = new int[m];

	cout << "ints = " << ints << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ints[i] << ", ";
		cout << *(ints + i) << "; ";
	}

	for (int i = 0; i < m; i++)
	{
		cout << ptrInts[i] << ", ";
		cout << *(ptrInts + i) << "; ";
	}

	//delete p;
	//delete[] ptrInts;

	int* a = new int(123);

	int ints2[3] = { 1, 2, 3 };
	int* ptrInts2 = new int[3]{ 2, 4, 6 };
	srand(1231);
	int* ptrInts3 = new int[10];
	int k = 3;
	for (int i = 0; i < 10; i++)
	{	
		//ptrInts3[i] = rand() % 11;
		ptrInts3[i] = rand() % 21 - 10;
		cout << ptrInts3[i];
		if (i != 9) cout << ", ";
			// 112 % 10 = 2
			// 541 % 10 = 1
		// 339 % 100 = 39 / 10 = (int)3.9 = 3
		// 14124124234
		// 5 / 3 = 1
		// 5 % 3 = 2
		// 65784 [-10; 10]
	}
	cout << endl;

	for (int i = k - 1; i < m - 1; i++)
	{
		ptrInts3[i] = ptrInts3[i + 1];
	}
	m--;

	for (int i = 0; i < m; i++)
	{
		cout << ptrInts3[i];
		if (i != m - 1) cout << ", ";
	}

	cout << "\nsdvig vlevo:\n";
	int first = ptrInts3[0];
	for (int i = 0; i < m - 1; i++)
	{
		ptrInts3[i] = ptrInts3[i + 1];
	}
	ptrInts3[m - 1] = first;

	for (int i = 0; i < m; i++)
	{
		cout << ptrInts3[i];
		if (i != m - 1) cout << ", ";
	}

}