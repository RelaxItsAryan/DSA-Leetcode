class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // Patterns such as a*, a*b*, a*b*c* can match empty string
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // Use the preceding character zero times
                    dp[i][j] = dp[i][j - 2];

                    // Use it one or more times, if it matches s[i - 1]
                    char previous = p[j - 2];

                    if (previous == '.' || previous == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                } 
                else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Direct character match or '.' wildcard
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};