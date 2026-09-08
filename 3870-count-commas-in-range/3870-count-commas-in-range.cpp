class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        for (int i = 1; i <= n; ++i) {
            int len = 0, x = i;
            while (x > 0) {
                ++len;
                x /= 10;
            }
            if (len > 3) {
                total += (len - 1) / 3;
            }
        }
        return (int)total;
    }
};