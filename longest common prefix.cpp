/*-- Write a function to find the longest common prefix string amongst an array of 
strings.
--*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> strs = {"prefix","prefer","present","president"};
	string longest = strs[0];
	
	auto iter1 = ++strs.begin();
	
	while ( iter1 != strs.end() )
	{
		for (int i=0;i<longest.size();++i)
		{
			if ( longest[i] != (*iter1)[i] )
			{
				longest = (*iter1).substr(0,i);
				break;
			}
		}
		iter1++;
	}
	
	cout << longest << endl;
	
}
