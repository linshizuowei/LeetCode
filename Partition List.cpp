/* -- Given a linked list and a value x, partition it such that all nodes less than x 
come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two 
partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
-- */


#include <iostream>
#include <vector>

using namespace std; 
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
	int x = 0;
	ListNode* head = new ListNode(1);
	
	ListNode* newhead = head;
	ListNode* returnhead = head;
	
    vector<int> before,after;
    while ( head != NULL){
        if (head->val < x){
            before.push_back(head->val);
        }
        else 
            after.push_back(head->val);
        head = head->next;
    }
    
    cout << after[0] <<endl;
    
    auto iter1 = before.begin();
    while (iter1 != before.end()){
        newhead->val = *iter1;
        newhead = newhead->next;
        iter1++;
    }
    
    auto iter2 = after.begin();
    while (iter2 != after.end()){
        newhead->val = *iter2;
        
        cout << newhead->val <<endl;
        
        newhead = newhead->next;
        
        iter2++;
        
    }
  return returnhead;	
	
}
	
/*	
	int x = 2;
	ListNode* head = new ListNode(1);
	ListNode* lastless = new ListNode(0);
	ListNode* p = head;
	ListNode* prep = lastless;
	
	while ( p != NULL ){
		if ( p->val < x ){
			prep->next = p->next;
			p->next = lastless->next;
			lastless->next = p;
			
			lastless = lastless->next;
			p = prep->next;
		}
		else {
			p = p->next;
			prep = prep->next;
		}
	}
*/
	

	/*ListNode *ptrX = head;
	while ( ptrX->val != x )
		ptrX = ptrX->next;
	
	ListNode *p = ptrX;
	
	ListNode *tmp = head;
	ListNode *prenode(0);
	prenode->next = head;
	
	while ( tmp->val != x ){
		if ( tmp->val >= x ){
			prenode->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;	
			p = p->next;
			tmp = prenode->next;
		}
		else {
			tmp = tmp->next;
			prenode = prenode->next;
		}
	}
	
	tmp = p;
	p = prenode;
	prenode = tmp;
	tmp = prenode->next;
	
	while ( tmp != NULL ){
		if ( tmp->val <= x ){
			prenode->next = tmp->next;
			tmp->next = p->next;
			p->next = tmp;
			p = p->next;
			tmp = prenode->next;
		}
		else {
			tmp = tmp->next;
			prenode = prenode->next;
		}
	}
	
	return head;
*/
