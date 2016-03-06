#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stack{
	string c;
	stack* pstack next;
}node *pnode;

int main()
{
	vector<string> stack;
	
	for (auto c : s){
		if ( c=='(' || c=='[' || c=='{' ){
			stack.push_back(c);
		}
		else {
			if ( stack.empty() )
				return false;
			
			if ( c - stack.back() == 1 || c - stack.back() == 2 ){
				stack.pop_back();
			}
			else 
				return false;
		}
	}
	
		
}




/*
string s;
	vector<string> left = {'(','[','{'};
	vector<string> right = {')',']','}'};
	
	pnode head = (pnode)malloc(sizeof(node));
	head->next = NULL;
	pnode top;
	
	for (auto c : s){
		if ( c=='(' || c=='[' || c=='{' ){
			pnode top = (pnode)malloc(sizeof(node));
			top->c = c;
			top->next = head->next;
			head->next = top;
			
		}
		else {
			if ( top == NULL )
				return false;
			if ( c == top->c ){
				head->next = top->next;
				pnode tmp = top;
				top = top->next;
				free(tmp);
			}
			else 
				return false;
		}
	}
*/
