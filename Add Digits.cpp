/*  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/


#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int s = (num % 9) >0? num - (num/9)*9:9;
	cout << s;
	return 0;
}
