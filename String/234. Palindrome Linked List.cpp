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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* mid = head;
		ListNode* tail = head;
		while (tail->next != nullptr&&tail->next->next != nullptr)
		{
			mid = mid->next;
			tail = tail->next->next;
		}
		mid = mid->next;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		while (mid)
		{
			next = mid->next;
			mid->next = pre;
			pre = mid;
			mid = next;
		}
		while (head&&pre)
		{
			if (head->val != pre->val)
				return false;
			pre = pre->next;
			head = head->next;
		}
		return true;


	}
};