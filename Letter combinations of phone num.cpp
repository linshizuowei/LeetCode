#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string digits = "021";
	vector<string> button = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int num;
	vector<string> Result = {""};
	vector<string> tmp;
	vector<string> container;
	vector<string> shit;
	
	for (auto i : digits){
		num = i-'0';
		tmp = Result;
		
		if ( button[num] == "" ) continue;
		
		shit = {};
		for ( auto j : button[num] ){
			container = tmp;
			
			for (auto k : container){
				k = k+j;
				shit.push_back(k);
			}
		}
		Result = shit;
	}
	
	for (auto i : Result)
		cout << i << endl;
}
