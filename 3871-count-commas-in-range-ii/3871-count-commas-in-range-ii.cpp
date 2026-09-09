class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;
        long long start = 1000;  // First threshold for 1 comma
        while (start <= n) {
            ans += (n - start + 1);  // Count numbers >= start
            start *= 1000;           // Next threshold (1M, 1B, ...)
        }
        return ans;
    }
};