#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int n;
	int k;
	
	vector<string> num(n,"1");
	string res;
	
	iota(num.begin(),num.end(),1);
	for (auto i : num)
		cout << i << endl;
}
