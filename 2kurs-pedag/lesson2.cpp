#include<iostream>
#include<ctime>
using namespace std;


void lesson_02() {
	srand(time(NULL));
	const int n = 10;
	int arr[n];

	cout << "arr = {";
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i];
		if (i != n - 1) cout<< ", ";
	}
	cout << "}\n";

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) {
			cout << arr[i];
			cout << ", ";
		}
	}

	// for (start; end; iter)
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] % 2 == 1) {
			cout << arr[i];
			if (i != 0) cout << ", ";
		}
	}

	cout << endl;

	cout << "Array18\n";

	bool b = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] < arr[n - 1]) {
			cout << arr[i] << endl;
			//continue;
			b = true;
			break;
		}
	}

	if (b == false) cout << "0\n";

	cout << "Array28\n";
	int min = arr[0];
	cout << min << ", ";
	for (int i = 2; i < n; i+=2)
	{
		cout << arr[i] << ", ";
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << endl;
	cout << "min = " << min << endl;

	int arr2[n];
	cout << "arr2 = {";
	for (int i = 0; i < n; i++)
	{
		arr2[i] = rand() % 100;
		cout << arr2[i];
		if (i != n - 1) cout << ", ";
	}
	cout << "}" << endl;

	int current;
	for (int i = 0; i < n; i++)
	{
		current = arr[i];
		arr[i] = arr2[i];
		arr2[i] = current;
	}

	cout << "arr = {";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1) cout << ", ";
	}
	cout << "}" << endl;

	cout << "arr2 = {";
	for (int i = 0; i < n; i++)
	{
		cout << arr2[i];
		if (i != n - 1) cout << ", ";
	}
	cout << "}" << endl;

}