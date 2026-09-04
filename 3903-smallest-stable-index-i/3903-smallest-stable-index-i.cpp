class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
         int n = nums.size();
        
        // Precompute suffix minimums
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        
        // Track prefix maximum and find first stable index
        int prefixMax = nums[0];
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            if (prefixMax - suffixMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};