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
    ListNode* partition(ListNode* head, int x) {
        ListNode pivot = ListNode(0);
        pivot.next = head;
        ListNode* cursor = &pivot;
        ListNode* pre = &pivot;
        ListNode* cur = head,*next = head;
        while(cur){
            next = cur->next;
            if(cur->val<x){
                if(cur!=cursor->next){
                    cur->next = cursor->next;
                    cursor->next = cur;
                    cursor = cur;
                    pre->next = next;
                    cur = next;
                }
                else{
                    cursor = cur;
                    pre = cur;
                    cur = next;
                }
            }
            else{
                pre = cur;
                cur = next;
            }
            
        }
        return pivot.next;
    }
};


int main(){
    ListNode *head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    Solution so;
    ListNode *res = so.partition(head,2);
    cout<<res->val<<" "<<res->next->val<<res->next->next->val;
}