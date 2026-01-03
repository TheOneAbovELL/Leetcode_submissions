class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead =
            new ListNode(0); // Dummy node to simplify result list creation
        ListNode* current = dummyHead; // Pointer to build the result list
        int carry = 0;                 // Carry value for sum > 9

        // Traverse both lists and process digit by digit
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry value

            // Add the current value from l1 if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in l1
            }

            // Add the current value from l2 if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in l2
            }

            // Update carry for next iteration
            carry = sum / 10;
            // Add the current digit to the result list
            current->next = new ListNode(sum % 10);
            current = current->next; // Move to the next node in the result list
        }

        return dummyHead->next; // The first node is a dummy node, so return the
                                // actual result
    }
};
