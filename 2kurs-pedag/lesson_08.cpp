#include<iostream>
using namespace std;


void lesson_08() {
	int staticArray[10];


	staticArray[0];
	// �������������; �������� �������; ���
	for (int i = 0; i < 10; i++)
	{
		// ���������1
		// ���������2
		// ���������3
		staticArray[i] = i + 1;
		cout << staticArray[i] << ' ';
	}
	cout << endl;

	for (int i = 10 - 1; i >= 0; i = i - 1) {
		cout << staticArray[i] << ' ';
	}
	cout << endl;

	for (int i = 1; i < 10; i = i + 2)
	{
		cout << staticArray[i] << ' ';
	}
	cout << endl;
	for (int i = 1; i < 10 / 2 + i % 2; i = i + 1)
	{
		cout << staticArray[2 * i - 1] << ' ';
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		staticArray[i] = rand() % 10 + 1;
		cout << staticArray[i] << ' ';
	}

}