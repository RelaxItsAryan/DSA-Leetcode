class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();

        for (int start = 0; start <= n - k; start++) {
            unordered_set<int> valuesInWindow;

            for (int i = start; i < start + k; i++) {
                valuesInWindow.insert(nums[i]);
            }

            for (int value : valuesInWindow) {
                count[value]++;
            }
        }

        int answer = -1;

        for (auto& [value, occurrences] : count) {
            if (occurrences == 1) {
                answer = max(answer, value);
            }
        }

        return answer;
    }
};