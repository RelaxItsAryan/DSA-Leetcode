class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> bad;

    void dfs(int u) {
        bad[u] = true;

        for (int v : adj[u]) {
            if (!bad[v])
                dfs(v);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        adj.resize(n);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        bad.assign(n, false);

        dfs(k);

        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!bad[u] && bad[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!bad[i])
                ans.push_back(i);
        }

        return ans;
    }
};