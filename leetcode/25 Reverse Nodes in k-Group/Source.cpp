#include <iostream>
using namespace std;

/*
	经验：常数意义上的时间增加，若能带来编程复杂度的降低，可以尝试，先完成，再优化。
	如此题：先遍历得到总共多少个节点
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverse(ListNode*& pre, ListNode *&last) {
		ListNode *final_tail = pre;
		ListNode *cur = pre->next;
		ListNode *next = NULL;

		while (cur != last) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		cur->next = pre;

		return final_tail;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *pivot = &ListNode(0);
		ListNode *pre_tail = pivot;
		ListNode *node = NULL;
		ListNode *next_head = NULL;
		bool exited = false;
		while ((!exited) && head) {
			node = head;
			for (int i = 0; i < k - 1; i++) {
				node = node->next;

				if (!node) {
					node = head;
					exited = true;
					break;
				}
			}
			pre_tail->next = node;
			if (!exited) {
				next_head = node->next;
				pre_tail = reverse(head, node);
				head = next_head;
			}
		}

		return pivot->next;
	}
};

int main() {

	ListNode n1 = ListNode(1);
	n1.next = &ListNode(2);
	n1.next->next = &ListNode(3);

	ListNode n2 = ListNode(4);
	n1.next->next->next = &n2;
	n2.next = &ListNode(5);


	Solution so;
	ListNode* r = so.reverseKGroup(&n1, 3);
	while (r) {
		cout << r->val;
		r = r->next;
	}
	system("Pause");
	return 0;
}