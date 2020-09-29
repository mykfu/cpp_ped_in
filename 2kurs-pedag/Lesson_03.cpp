#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

int main() {

	const int rows = 6;
	const int cols = 3;
	const int length = 8;

	int anArray[length];

	int matr[rows][cols];
	int cube[length][length][length];
	//time_t t = time(0);
	time_t t = 1601367697;
	cout << "time = " << t << endl;
	srand(t);

	for (int i = 0; i < length; i++)
	{
		anArray[i] = rand() % 100;
		cout << anArray[i] << " ";
	}
	cout << endl;

	int max = anArray[0];

	for (int i = 1; i < length; i++)
	{
		if (max < anArray[i]) {
			max = anArray[i];
		}
	}
	cout << "max = " << max << endl << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matr[i][j] = rand() % 100;
			cout << setw(3) << matr[i][j];
		}
		cout << endl;
	}


	for (int i = 0; i < cols; i++)
	{
		max = matr[0][i];
		for (int j = 0; j < rows; j++)
		{
			if (max < matr[j][i]) {
				max = matr[j][i];
			}
		}
		cout << "max for " << i << " is " << max << ".\n";
	}

	int maxCount = 1;
	int maxCountIndex = 0;
	for (int i = 0; i < cols; i++)
	{
		int curCount = 1;
		for (int j = 0; j < rows; j++)
		{
			for (int k = j + 1; k < rows; k++)
			{
				if (matr[j][i] == matr[k][i]) {
					curCount++;
				}
			}
		}
		if (maxCount < curCount) {
			maxCount = curCount;
			maxCountIndex = i;
		}
	}
	cout << "max count = " << maxCount 
		 << ", index = " << maxCountIndex << endl;


}