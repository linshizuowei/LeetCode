/*-- Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
--*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "      -11919730356x";
	int size = sizeof(str);
	int i;
	int sigal = 0;
	int sigal2 = 0;
	int sigal3 = 0;
	int opt = 1;
	
	long long LNnum = 0;
	int ending = 0;
	
	for (auto s : str){
		i = (int)s;
		if (i == 32 && sigal == 0){
			ending = 0;
			continue;
		}
		
		if (i==43 || i == 45 || (i>47 && i<58)){
			if (sigal == 0){
				switch (i) {
					case 43 :
						sigal = 1;
						break;
					case 45 :
						sigal = 1;
						opt = -1;
						break;
					default:
						sigal = 1;
	
						LNnum = i-48;
						++sigal2;
				}
			}else {
				switch (i){
					case 43 :
						ending = -1;
						break;
					case 45 :
						ending = -1;
						break;
					default :
						if (sigal3 == 1){
							if (opt == 1){
								cout << 2147483647 << endl;
								ending = -1;
							}
							else{
								cout << -2147483648 << endl;
								ending = -1;
							} 
								
						}
						LNnum = LNnum * 10 + (i-48);
						++sigal2;
				}
			}
		}else {
			ending = -1;
		}
		
		if (ending == -1)
			break;
		
		if (sigal2 == 10){
			if (LNnum * opt > 2147483647){
				cout << 2147483647 << endl;
				ending = -1;
			}else if (LNnum * opt < -2147483648){
				cout << -2147483648 << endl;
				ending = -1;
			}else {
				sigal3 = 1;
			}
		}
		
		if (ending == -1)
			break;
		
		
	}
	
	LNnum *= opt;
	cout << LNnum << endl;
}
