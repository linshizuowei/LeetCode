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
	
