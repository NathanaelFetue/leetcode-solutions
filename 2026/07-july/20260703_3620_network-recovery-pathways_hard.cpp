/*
 * Problem #3620 - Network Recovery Pathways (Hard)
 * URL: https://leetcode.com/problems/network-recovery-pathways/
 *
 * Approach: Binary search on the minimum edge weight combined with Dijkstra's shortest path algorithm.
 * We binary search on the answer (minimum allowed edge weight threshold), and for each candidate threshold,
 * we run Dijkstra from node 0 to node n-1 using only edges with weight >= threshold, checking if the total
 * path cost stays within budget k. We maximize the minimum edge weight on a valid path.
 *
 * Time Complexity: O(E * log(W) * log(E)) where E = number of edges, W = max edge weight range.
 *   - Binary search over edge weights: O(log W)
 *   - Each Dijkstra run: O((E + V) log V) ~ O(E log E)
 *
 * Space Complexity: O(V + E) for adjacency list, distance array, and priority queue.
 *
 * Runtime : 203 ms
 * Memory  : 303.3 MB
 */

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);
        int l = INT_MAX, r = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (!online[u] || !online[v]) {
                continue;
            }
            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dis(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                           greater<>>
                q;

            dis[0] = 0;
            q.push({0, 0});

            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();

                if (d > k) {
                    return false;
                }
                if (u == n - 1) {
                    return true;
                }
                if (d > dis[u]) {
                    continue;
                }

                for (auto& [v, w] : g[u]) {
                    if (w < mid) {
                        continue;
                    }
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
            return false;
        };

        if (!check(l)) {
            return -1;
        }

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
