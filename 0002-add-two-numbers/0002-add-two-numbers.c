struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *cur = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) sum += l1->val, l1 = l1->next;
        if (l2) sum += l2->val, l2 = l2->next;

        cur = cur->next = malloc(sizeof(struct ListNode));
        cur->val = sum % 10;
        cur->next = NULL;
        carry = sum / 10;
    }

    return dummy.next;
}