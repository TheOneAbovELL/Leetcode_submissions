class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* sorted=dummy;
        ListNode* cur=head;
        while(cur){
            if(cur->next&&cur->next->val<cur->val){
                ListNode* prev=dummy;
                while(prev->next&&prev->next->val<cur->next->val){
                    prev=prev->next;
                }
                ListNode* node=cur->next;
                cur->next=node->next;
                node->next=prev->next;
                prev->next=node;
            }else{
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};