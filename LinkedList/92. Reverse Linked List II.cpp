/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		ListNode p(0);
		p.next = head;
		n -= m - 1;
		ListNode* ph = &p;
		ListNode* before = &p;
		while (--m)
		{
			ph = ph->next;
			before = before->next;
		}
		ph = ph->next;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (n--)
		{
			next = ph->next;
			ph->next = pre;
			pre = ph;
			ph = next;
		}
		before->next->next = next;
		before->next = pre;
		return p.next;

	}
};