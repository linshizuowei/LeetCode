/*-- Given a string, find the length of the longest substring without repeating 
characters. For example, the longest substring without repeating letters for "abcabcbb"
 is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the 
 length of 1.
 --*/

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <ctime>

using namespace std;


int main()
{

//	//A:65  a:97  0:48
//	string a = "abc";
//	cout << a[2]-97;
	clock_t start,end;
	start = clock();
 
	

	vector<int> table(127,-1);
	
	string s = "pwwkew";
	int n = s.size();
	int longest = 0;
	int length = 0;
	int tmp = 0;
	int j;

	
	

		for ( j=0;j<n;++j){
			int x = s[j];
			if (table[x] == -1 || table[x] < tmp){
				table[x] = j;
				++length;
			}
			else {
				if ( longest < length ){
					longest = length;
				}
				tmp = table[x];
				length = j-table[x];
				table[x] = j;
//				table[x] = j;
//				
//				length = j-tmp;
//				tmp = table[x];
//				for (int k=tmp;k<j;++k){
//					if (s[k] == s[j]){
//						length -= (k-tmp+1);
//						tmp = k+1;
//						--j;
//						break;
//					}
//				}
			
			}
		}
		if ( j == n){
			if ( longest < length ){
				longest = length;
			}
	
		}
			
	
	cout << longest << endl;
	
	end = clock();
	cout << "running time:" << (double)(end-start)/CLOCKS_PER_SEC;
}

