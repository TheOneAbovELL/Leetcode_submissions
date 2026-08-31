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
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        int f=-1,l=-1,m=1e9,i=1;
        ListNode* p=h;
        ListNode* c=h->next;
        while(c->next){
            int n=c->next->val;
            if((c->val>p->val&&c->val>n)||(c->val<p->val&&c->val<n)){
                if(f==-1) f=i;
                else m=min(m,i-l);
                l=i;
            }
            p=c; c=c->next; i++;
        }
        if(m==1e9) return {-1,-1};
        return {m,l-f};
    }
};