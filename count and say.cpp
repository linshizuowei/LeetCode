#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n= 4;
	int cnt = 0;
	string s;
	string next = "1";
	string temp;
	stringstream ss;
	char key;
	int j;
	
	for (int i=0;i<n;++i){
		
		s = next;
		
		next.clear();
		key = s[0];
		cnt = 0;
		for (j=0;j<s.size();++j){
			if ( s[j] == key ){
				cnt++;
			}
			else {
				ss << cnt;
		
				ss >> temp;
		
				temp += s[j-1];
				next += temp;
		
				
				ss.clear();
				temp.clear();
				cnt = 1;
				key = s[j];
			}
			
		}
		
		ss << cnt;
		
		ss >> temp;
		
		temp += s[j-1];
		next += temp;
		
		
		ss.clear();
		temp.clear();
		cnt = 1;
		key = s[j];
		
	}
	
	cout << s;
}
