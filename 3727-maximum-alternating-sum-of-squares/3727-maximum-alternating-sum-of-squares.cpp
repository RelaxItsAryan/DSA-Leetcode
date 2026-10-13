class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);

        for (int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }

        sort(sq.begin(), sq.end());

        long long ans = 0;
        int minusCount = n / 2;   // odd indices

        for (int i = 0; i < minusCount; i++) {
            ans -= sq[i];         // smaller squares subtracted
        }
        for (int i = minusCount; i < n; i++) {
            ans += sq[i];         // larger squares added
        }

        return ans;
    }
};