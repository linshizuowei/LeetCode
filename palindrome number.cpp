/* Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num = -2147483648;
	int e = 1;
	
	if ( num == 0 )
		return true;
	while ( num / (long long)pow(10,e) != 0 ){
		cout << "here" << endl;
		++e;
	}
	
	int i = e;
	int head = 0;
	int tail = 0;
	while ( i >= 1 ){
		head = num / (int)pow(10,i-1);
		tail = num % 10;
		if ( head != tail )
			cout << "false" << endl;
		num = num % (int)pow(10,i-1);
		num = num / 10;
		i -= 2;
	}
	
	cout << "true" <<endl;
}
