#include<iostream>
#include<iomanip>
#include<ctime>
#include<string>

#define PI 3.1415926
#define sqr(X) ((X)*(X)) // 3+2*3+2

#define out(X) (cout << #X << " = " << X << endl)

#define newvar(X) X##_

using namespace std;

double f(double x) {
	if (x < 0) return x * x * x;

	return x * x;
}

double f(double x, double y, int n = 0) {
	return x * x;
}

//void func(int n = 0) {
//	cout << n << endl;
//	func(++n);
//
//	return;
//}

int factorial(int n) {
	cout << n;
	if (n == 0 || n == 1) {
		cout << " = ";
		return 1;
	}
	cout << " * ";
	return n * factorial(n - 1);
}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

double sum(double a, double b) {
	return a + b;
}

int sum(int a, int b) {
	return a + b;
}

template<typename T, typename U>
T sum(T a, U b) {
	return a + b;
}


double g(double x);

double g(double x) {
	//return std::pow(sin(x), 2);
	return sin(x) * sin(x);
}

double integral(double a, double b, int n = 1000) {
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum += g(a + (i - 0.5) * (b - a) / n);
	}

	return (b - a) / n * sum;
}

void lesson_04() {


	const double pi = 3.14;

	cout << f(2) << endl;

	f(1, 2);

	cout << factorial(5) << endl;

	int a = 4, b = 10;
	cout << "a = " << a << ", b = " << b << endl;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;

	cout << "sum(1, 3) = " << sum(1, 3) << endl;
	string s1 = "1";
	string s2 = "3";
	cout << "sum(1, 3) = " << sum(s1, s2) << endl;

	cout << PI << endl;

	cout << sqr(3 + 2) << endl;

	out(factorial(a + 1));
	string s1_ = "s1_ test\n";
	cout << newvar(s1);

	out(integral(0, 1));
	out(integral(0, 1, 10));

}

