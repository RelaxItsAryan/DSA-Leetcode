class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;      // index of first critical point
        int prevCp = -1;     // index of previous critical point
        int last = -1;       // index of last critical point
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr->next) {
            ListNode* nxt = curr->next;
            if ((curr->val > prev->val && curr->val > nxt->val) ||
                (curr->val < prev->val && curr->val < nxt->val)) {
                if (first == -1) {
                    first = idx;
                } else {
                    minDist = min(minDist, idx - prevCp);
                }
                prevCp = idx;
                last = idx;
            }
            prev = curr;
            curr = nxt;
            idx++;
        }

        if (first == -1 || first == last) return {-1, -1};
        return {minDist, last - first};
    }
};