#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num;
	int R = 0;
	cin >> num;
	
//	for (int i = 2;i<=num/2;i++){
//		int sigal = 0;
//		if ( num%i == 0 ){
//			if ( i%2 == 0 )
//				continue;
//			for ( int j=3;j<sqrt(i);j+=2){
//				if ( i%j == 0 ){
//					sigal = -1;
//					break;
//				}
//			}
//			if ( sigal == 0 ){
//				if ( i>5 ){
//					R == 1;
//					break;
//				}
//			}
		
	while ( num%2 ==0 )
		num /= 2;
	while ( num%3 == 0 )
		num /= 3;
	while ( num%5 == 0 )
		num /= 5;
	if ( num != 1 )
		R == 1;
		
		
//		}
//	}
	
	if ( R == 1 )
		cout << "false";
	else 
		cout << "true";
		
	return 0;
}
