#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s = "(((()((())";
	
	int cnt = 0;
	int max = 0;
	int j = -1;
	vector<char> v;
	
	for ( int i=0;i<s.size();i++){
		if ( s[i] == '(' ){
			j = i;
			v.push_back(s[i]);
		}
		else {
			if ( j >= 0 && s[j] == '(' ){
				v.push_back(' ');
				v[j] = ' ';
				
				while ( j >= 0){
					if ( v[j] == '(' )
						break;
					j--;
				}
			}
			else {
				v.push_back(s[i]);
			}
		}
	}
	
	for ( int i=0;i<v.size();i++){
		if ( v[i] != ' ' ){
			if ( max < cnt )
				max = cnt;
			cnt = 0;
		}
		else {
//			cout << v[i];
			cnt++;
		}
	}
	if ( max < cnt )
		max = cnt;
	cout << v.size() << endl;
//	for ( auto i : v )
//		cout << i <<' ' << endl;
	cout << max;
}
