#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return mergeK(lists, 0, lists.size() - 1);
	}
	ListNode* mergeK(vector<ListNode*>& lists, int start, int end) {
		if (end - start == 1) {
			return mergeTwo(lists[start], lists[end]);
		}
		else if (start == end) {
			return lists[start];
		}
		else {
			int mid = (start + end) / 2;
			ListNode* first = mergeK(lists, start, mid);
			ListNode* second = mergeK(lists, mid + 1, end);
			return mergeTwo(first, second);
		}
	}
	ListNode* mergeTwo(ListNode* first, ListNode* second) {
		ListNode* temp_first = first;
		ListNode* temp_second = second;
		ListNode res = ListNode(0);
		ListNode *res_node = &res;
		while (temp_first != NULL && temp_second != NULL) {
			if (temp_first->val < temp_second->val) {
				res_node->next = temp_first;
				temp_first = temp_first->next;
			}
			else {
				res_node->next = temp_second;
				temp_second = temp_second->next;
			}
			res_node = res_node->next;
		}
		if (temp_first == NULL) {
			res_node->next = temp_second;
		}
		else {
			res_node->next = temp_first;
		}
		return res.next;
	}
};

int main() {

	vector<ListNode*> test;
	ListNode n1 = ListNode(1);
	n1.next = &ListNode(4);
	n1.next->next = &ListNode(5);
	test.push_back(&n1);

	ListNode n2 = ListNode(1);
	n2.next = &ListNode(3);
	n2.next->next = &ListNode(4);
	test.push_back(&n2);

	ListNode n3 = ListNode(2);
	n3.next = &ListNode(6);
	test.push_back(&n3);

	Solution so;
	ListNode* r = so.mergeKLists(test);
	while (r) {
		cout << r->val;
		r = r->next;
	}
	return 0;
}