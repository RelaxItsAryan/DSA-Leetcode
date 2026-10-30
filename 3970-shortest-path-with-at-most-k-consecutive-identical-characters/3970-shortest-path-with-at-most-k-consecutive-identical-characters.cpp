#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
        }

        const int INF = INT_MAX;

        // dist[node][run] = minimum cost to reach node
        // with exactly `run` consecutive identical labels at the end
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));
        dist[0][1] = 0;

        // {cost, node, currentRunLength}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();

            if (d > dist[u][run]) continue;

            if (u == n - 1) return d;

            for (auto [v, w] : graph[u]) {
                int nextRun;

                if (labels[v] == labels[u]) {
                    nextRun = run + 1;
                    if (nextRun > k) continue;
                } else {
                    nextRun = 1;
                }

                int nd = d + w;

                if (nd < dist[v][nextRun]) {
                    dist[v][nextRun] = nd;
                    pq.push({nd, v, nextRun});
                }
            }
        }

        return -1;
    }
};