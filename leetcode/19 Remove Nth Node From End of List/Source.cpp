#include <algorithm>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return NULL;
		ListNode pivot(0);
		pivot.next = head;
		ListNode* end = head;
		ListNode* remove = &pivot;
		for (int i = 0; i < n; i++) {
			end = end->next;
		}
		while (end != NULL) {
			end = end->next;
			remove = remove->next;
		}
		remove->next = remove->next->next;
		return head;
	}
};

int main() {
	Solution so;
	ListNode h(1);
	so.removeNthFromEnd(&h,1);
}