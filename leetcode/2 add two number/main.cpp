#include <stdio.h>
#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	int digit_plus_transform(int a, int b, int &carry) {
		int sum = a + b + carry;
		if (sum >= 10)
		{
			carry = 1;
			return sum - 10;
		}
		else
		{
			carry = 0;
			return sum;
		}
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;

		ListNode res(digit_plus_transform(l1->val, l2->val, carry));

		ListNode* iter1 = l1->next;
		ListNode* iter2 = l2->next;
		ListNode* iter_res = &res;
		while (iter1 || iter2)
		{
			if (!iter1)
			{
				// cannot directly use ListNode node(...) because the same name will be confilct
				ListNode* node = new ListNode(digit_plus_transform(0, iter2->val, carry));
				iter_res->next = node;
				iter2 = iter2->next;
			}
			else if (!iter2)
			{
				ListNode* node = new ListNode(digit_plus_transform(iter1->val, 0, carry));
				iter_res->next = node;
				iter1 = iter1->next;
			}
			else
			{
				ListNode* node = new ListNode(digit_plus_transform(iter1->val, iter2->val, carry));
				iter_res->next = node;
				iter1 = iter1->next;
				iter2 = iter2->next;
			}
			iter_res = iter_res->next;

		}
		if (carry == 1)
		{
			ListNode* node = new ListNode(1);
			iter_res->next = node;
		}
		return &res;
	}
};

int main() {
	ListNode node1(2);
	node1.next = new ListNode(4);
	node1.next->next = new ListNode(3);

	ListNode node2(5);
	node2.next = new ListNode(6);
	node2.next->next = new ListNode(4);
	Solution* so = new Solution();
	ListNode* res = so->addTwoNumbers(&node1, &node2);
	printf("%d", res->val);
	return 0;
}