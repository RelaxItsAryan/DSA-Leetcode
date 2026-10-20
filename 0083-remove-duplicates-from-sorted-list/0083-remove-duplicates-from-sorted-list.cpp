class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* dup = curr->next;
                curr->next = dup->next;
                delete dup; // optional in LeetCode
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};