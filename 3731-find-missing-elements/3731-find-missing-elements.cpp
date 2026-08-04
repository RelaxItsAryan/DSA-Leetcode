class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mini = nums[0], maxi = nums[0];
        unordered_set<int> s;
        for (int num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
            s.insert(num);
        }
        vector<int> ans;
        for (int i = mini; i <= maxi; i++) {
            if (s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};