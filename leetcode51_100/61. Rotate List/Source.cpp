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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *node = head;
        int list_size=1;

        while(node->next!=NULL){
            node=node->next;
            list_size++;
        }
        node->next = head;
        k = list_size - k%list_size;
        
        ListNode *res;
        node = head;
        for(int i=0;i<k-1;i++){
            node=node->next;
        }
        res = node->next;
        node->next = NULL;
        return res;
    }
};