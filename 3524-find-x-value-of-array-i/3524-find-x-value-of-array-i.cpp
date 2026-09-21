class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);
            int value = num % k;

            // Start a new subarray containing only nums[i]
            newDp[value]++;

            // Extend all previous subarrays
            for (int remainder = 0; remainder < k; remainder++) {
                int newRemainder = (remainder * value) % k;
                newDp[newRemainder] += dp[remainder];
            }

            // Add all subarrays ending at the current index
            for (int remainder = 0; remainder < k; remainder++) {
                answer[remainder] += newDp[remainder];
            }

            dp = newDp;
        }

        return answer;
    }
};