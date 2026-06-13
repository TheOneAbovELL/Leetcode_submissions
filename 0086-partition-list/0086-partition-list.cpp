/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(0);
        ListNode* greater=new ListNode(0);
        ListNode* l=less,*g=greater;
        while(head){
            if(head->val<x){
                l->next=head;
                l=l->next;
            }else{
                g->next=head;
                g=g->next;
            }
            head=head->next;
        }
        g->next=nullptr;
        l->next=greater->next;
        return less->next;
    }
};