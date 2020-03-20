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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pointer;
        while(head){
            if((!head->next)||head->val!=head->next->val){
                break;
            }
            pointer = head->next;
            while(pointer&&pointer->val==head->val){
                pointer=pointer->next;
            }
            head=pointer;
        }
        
        if(!head) return NULL;
        ListNode* pre_solid = head;
        ListNode* node = head->next;
        
        head->next=NULL;
        while(node){
            if(!node->next){
                pre_solid->next=node;
                return head;
            }
            if(node->next->val!=node->val){
                pre_solid->next=node;
                pre_solid = node;
                node = node->next;
                pre_solid->next=NULL;
            }
            else{ // duplicate
                pointer = node->next;
                while(pointer&&pointer->val==node->val){
                    pointer=pointer->next;
                }
                node = pointer;
            }
        }
        
        return head;
    }
};