class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int m = k;
        while (seen.count(m)) {
            m += k;
        }
        return m;
    }
};