#include <iostream>
#include <limits.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int dividend = 2147483647;
	int divisor = 1;
	
	if ( !divisor || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;
	
	int sign = ( (dividend < 0) ^ (divisor < 0) )? -1 : 1;
	
	long long dvd = abs(dividend);
	long long dvs = abs(divisor);
	int sum = 0;
	long long tmp;
	int k;
	
	while ( dvd >= dvs ){
		tmp = dvs;
		k = 1;
		while (dvd >= (tmp << 1)){
			k += k;
			tmp <<= 1;
		}
		
		dvd -= tmp;
		sum += k;
	}
	
	cout << (sign==1 ? sum : -sum) << endl;
	
}
