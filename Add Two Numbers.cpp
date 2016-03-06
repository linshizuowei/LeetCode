#include <iostream>
#include <memory>
#include <ctime>

using namespace std;

struct ListNode;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


int main()
{
	clock_t start,end;
	start = clock();
	
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	ListNode *l11 = new ListNode(6);
	ListNode *l12 = new ListNode(4);
	ListNode *l13 = new ListNode(7);
	l1->next = l11;
	l11->next = l12;
	l12->next = l13;
	ListNode *l21 = new ListNode(5);
	ListNode *l22 = new ListNode(6);
	ListNode *l23 = new ListNode(4);
	l2->next = l21;
	l21->next = l22;
	l22->next = l23;

	ListNode *sum = new ListNode(0);
	ListNode *p = new ListNode(0);
	
	p->next = sum;
	int s = 0;
	int tmp = 0;
	
//	int sigal = 0;
	
	while ( l1 != NULL && l2 != NULL ){
		tmp = l1->val + l2->val + s;
		++sigal;
//		cout << "tmp :" << tmp << endl;
		if ( tmp > 9 ){
			p->next->val = tmp % 10;
			s = 1;
		}
		else {
			p->next->val = tmp;
			s = 0;
		}
	
		ListNode *ptr = new ListNode(0);
		p->next->next = ptr;
		p->next = ptr;
		
					
		
		l1 = l1->next;
		l2 = l2->next;
		
		
	}
	
	while ( l1 != NULL ){
		if ( l1->val + s > 9){
			p->next->val = (l1->val+s) % 10;
			s = 1;
		}
		else {
			p->next->val = l1->val+s;
			s = 0;
		}
		
		ListNode *ptr = new ListNode(0);
		p->next->next = ptr;
		p->next = ptr;
		
		l1 = l1->next;
	}
	
	
	while ( l2 != NULL ){
		if ( l2->val + s > 9){
			p->next->val = (l2->val+s) % 10;
			s = 1;
		}
		else {
			p->next->val = l2->val+s;
			s = 0;
		}
		
		ListNode *ptr;
		p->next->next = ptr;
		p->next = ptr;
		
		l2 = l2->next;
	}
	
	if ( s == 1 ){
		p->next->val = 1;
	}
	else{
		
		delete p->next;
//		cout << "delete" << endl;
	}
	
	cout << sum->val << endl;
	cout << sum->next->val << endl;
	cout << sum->next->next->val << endl;
	cout << sum->next->next->next->val<< endl;
	cout << sum->next->next->next->next->val<< endl;
	
	end = clock();
	cout << "running time:" << (double)(end-start)/CLOCKS_PER_SEC;
}
