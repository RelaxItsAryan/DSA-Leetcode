class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M, vector<int>& piles) {

        // We can take all remaining piles
        if (i + 2 * M >= n) {
            return suffix[i];
        }

        // Already calculated
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            int nextM = max(M, X);

            // Current player gets all remaining
            // minus what the opponent can get
            int current = suffix[i] -
                           solve(i + X, nextM, piles);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // Suffix sum
        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = piles[i] + suffix[i + 1];
        }

        // dp[i][M]
        dp.assign(n, vector<int>(2 * n + 1, -1));

        return solve(0, 1, piles);
    }
};