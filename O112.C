#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


/**
int close(double in, long guess) {
	if (-0.0001 < in - guess && in - guess < 0.0001) {
		return 1;
	}
	return 0;
}

long long toint(long double in)
{
	long long  guess = ceil(in);
	if (close(in, guess) == 1) {
		return guess;
	}
	else if (close(in,guess-1) == 1) {
		return guess - 1;
	}
	else if (close(in,guess-2) == 1) {
		return guess - 2;
	}
}

long double sq5 = pow(5,0.5);
long double base1 = (1 + sq5) / 2;
long double base2 = (1 - sq5) / 2;

long long fib(int index) {
	long long result;
	long double r = (pow(base1, index) - pow(base2, index))/sq5;
	result = toint(r);
	return result;
}
**/


int main()
{
vector<long> a;
long ans0 = 2, ans1 = 3;
a.push_back(ans0);
a.push_back(ans1);
long mod = pow(10,9) + 7;
for (int i = 2; i < 10000; ++i) {
	long add = (a[i-1]+a[i-2])%mod;
	a.push_back(add);
}


	int num,temp;
	vector<long> out;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i) {
		scanf("%d", &temp);
		out.push_back(a[temp-1]);
	}
	for (int i = 0; i < num; ++i) {
		printf("%li\n", out[i]);
	}

}
