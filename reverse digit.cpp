/*-- Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
--*/

#include <iostream>
#include <math.h>

using namespace std;

void method1(int x);

int main()
{
	int x = -2147483648;
	method1(x);
}

void method1(int x)
{
	long long n = 1;
	int s = 0;
	int t = 0;
	long long tmp = 0;
	int reN = 0;
	int k = 1;
	long long LreN = 0;
	
		
	
	while ( x/n != 0 ){
		++s;
		n = (long long)pow(10,s);
		cout << "x : " << x << endl;
	}
	cout << s << endl;
	t = --s;
	
	while ( s >= 0 ){
		tmp = x/((int)pow(10,s));
		reN += tmp*((int)pow(10,t-s));
		LreN += tmp*((int)pow(10,t-s));
		x = x%((int)pow(10,s));
		--s;
	}
	cout << reN << endl;
	cout << LreN << endl;
}
