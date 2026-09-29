class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length.
        if ((m + n - 1) % 2 != 0) return false;

        // Must begin with '(' and end with ')'.
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        // dp[i][j][bal] = Can we reach (i, j) with balance = bal?
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        dp[0][0][1] = true; // grid[0][0] is '('

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int bal = 0; bal < m + n; bal++) {
                    int prevBalance = bal - change;

                    if (prevBalance < 0 || prevBalance >= m + n) {
                        continue;
                    }

                    bool fromTop = (i > 0 && dp[i - 1][j][prevBalance]);
                    bool fromLeft = (j > 0 && dp[i][j - 1][prevBalance]);

                    if (fromTop || fromLeft) {
                        dp[i][j][bal] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};