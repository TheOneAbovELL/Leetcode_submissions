struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    for (int i = 0; i < n + 1; ++i) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* to_delete = slow->next;
    slow->next = slow->next->next;
    return dummy.next;
}
