#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* reverseKGroup(ListNode *head,int k);

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	ListNode *q = head;
	
	for (int i=2;i<4;i++){
		ListNode *tmp = new ListNode(i);
		p->next = tmp;
		p = p->next;
	}
	
	while (q != NULL ){
		cout << q->val <<endl;
		q = q->next;
	}
	
	ListNode *l = reverseKGroup(head,3);
	
	while (l != NULL ){
		cout << l->val <<endl;
		l = l->next;
	}
}

ListNode* reverseKGroup(ListNode *head,int k)
{
	ListNode *pre = new ListNode(0);
	pre->next = head;
	
	int cnt = 0;
	ListNode *tmp = head;
	while ( tmp != NULL ){
		if (++cnt == k){
			pre->next = tmp;
		}
		tmp = tmp->next;
	}
	
	if (cnt < k) return head;
	
	int segment = cnt / k;
	
	int i = 0;
	int s = 0;
	int j = 0;
	ListNode *p = head;
	ListNode *q = p;
	ListNode *back;
	ListNode *front;
	ListNode *tag = pre;
	
	while ( i < segment ){
		s = 0;
		while ( s < k-1){
			s++;
			q = q->next;
			
		}
		
		j = 0;
		back = q->next;
		
		tag->next = q;
		tag = p;
		
//		cout << k-1 << endl;
		
		while ( j < k-1 ){
			front = p->next;
			p->next = q->next;
			q->next = p;
			p = front;
			j++;
//			cout << j << endl;
			cout << "in where" <<endl;
		}
		
		cout << "here"<< endl;
		p = back;
		q = p;
		
		i++;
	}
	
	return pre->next;
}
