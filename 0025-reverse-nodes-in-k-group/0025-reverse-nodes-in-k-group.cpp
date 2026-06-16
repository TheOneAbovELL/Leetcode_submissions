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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy,*cur=head;
        while(true){
            ListNode* tail=prev;
            for(int i=0;i<k;i++){
                tail=tail->next;
                if(!tail) return dummy->next;
            }
            ListNode* nextGroup=tail->next;
            ListNode* prevNode=nullptr,*node=cur;
            while(node!=nextGroup){
                ListNode* next=node->next;
                node->next=prevNode;
                prevNode=node;
                node=next;
            }
            prev->next=tail;
            cur->next=nextGroup;
            prev=cur;
            cur=nextGroup;
        }
        return dummy->next;
    }
};