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
        if (!head || k == 1) return head;

        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (true) {
            // Check if there are at least k nodes ahead
            ListNode* check = prev;
            for (int i = 0; i < k; ++i) {
                check = check->next;
                if (!check) return dummy.next; // fewer than k nodes left
            }

            // Start of the group to reverse
            ListNode* groupStart = prev->next;
            ListNode* curr = groupStart;
            ListNode* prevGroup = prev;

            // Reverse k nodes
            ListNode* prevNode = nullptr;
            ListNode* nextNode = nullptr;
            for (int i = 0; i < k; ++i) {
                nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode;
            }

            // Connect previous part to new head of reversed group
            prevGroup->next = prevNode;
            // Connect tail of reversed group to the rest
            groupStart->next = curr;

            // Move prev to the tail of this reversed group
            prev = groupStart;
        }

        return dummy.next;
    }
};