#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string num1 = "123456789";
	string num2 = "987654321";
	int size1 = num1.size();
	int size2 = num2.size();
	
	int add = 0;
	int digit1 = 0;
	int digit2 = 0;
	vector<int> multi;
	int bit = 0;
	
//	if ( num1 == "0" || num2 == "0" )
//		return "0";
		
	for (int i=0;i<size2+size1;i++)
		multi.push_back(0);
		

	for (int i=size1-1; i>=0; --i){
		digit1 = num1[i]-48;
		
		for (int j=size2-1,k=size1-1-i; j>=0; --j,++k){
			digit2 = num2[j]-48;
			
			bit = (digit1 * digit2) % 10 + add;
			//cout << "bit=: " <<bit<< endl;
			add = (digit1 * digit2) / 10;
			//cout << "add=: " << add <<endl;
			
			if (multi[k] + bit > 9){
				add = (multi[k] + bit)/10 + add;
				multi[k] = (multi[k] + bit)%10;
			
			}
			else 
				multi[k] += bit; 
			
			
			for (int m=1;;m++){
				if (multi[k+m] + add > 9){
					int temp = add;
					add = (multi[k+m]+add)/10;
					multi[k+m] = (multi[k+m] + temp)%10;
				
				}
				else{
					multi[k+m] += add;
					add = 0;
					break;
				}
			}
			
			
		}
		
		
	}
	
	for (auto i : multi)
		cout << i <<' ';
	cout <<endl;
	
	string s;
	if (multi.back() == 0){
		for (int i=multi.size()-2;i>=0;i--){
			s.push_back(multi[i]+48);
		}
	}
	else {
		for (int i=multi.size()-1;i>=0;i--)
			s.push_back(multi[i]+48);
	}
	
	cout << s;
}
