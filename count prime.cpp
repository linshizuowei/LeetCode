#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int n = 3;
	vector<bool> isprime(n,true);
	int i = 2;
	int j = 1;
	int cnt = 0;
	
	isprime[0] = false;
	isprime[1] = false;
	
	for (i=2;i<sqrt(n);i++) {
		if ( isprime[i] == false )
			continue;
		//j = i;
		
		for (j=i;j<sqrt(n);j++) {
			isprime[i*j] = false;
			//j++;
		}
		
		//i++;
	}
	
	for ( auto s : isprime ){
		if ( s == true )
			cnt++;
	}
	return cnt;
}
