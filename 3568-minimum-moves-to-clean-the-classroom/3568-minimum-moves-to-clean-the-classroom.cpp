class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();

        // d[i][j] = bit index of the litter at (i,j)
        vector<vector<int>> d(m, vector<int>(n, 0));
        int sx = 0, sy = 0, cnt = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') { sx = i; sy = j; }
                else if (classroom[i][j] == 'L') d[i][j] = cnt++;
            }
        if (cnt == 0) return 0;                 // nothing to collect

        // mask bits = litter that is still NOT collected; goal = 0
        int full = (1 << cnt) - 1;
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << cnt, false))));

        queue<array<int, 4>> q;                 // {row, col, curEnergy, mask}
        q.push({sx, sy, energy, full});
        vis[sx][sy][energy][full] = true;

        int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, e, mask] = q.front(); q.pop();

                if (mask == 0) return ans;      // all litter collected
                if (e <= 0) continue;           // no energy -> cannot move on

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int ne = (classroom[nr][nc] == 'R') ? energy : e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L') nmask &= ~(1 << d[nr][nc]);

                    if (!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};