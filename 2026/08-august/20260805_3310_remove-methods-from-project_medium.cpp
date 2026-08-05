/*
 * Problem #3310 - Remove Methods From Project (Medium)
 * https://leetcode.com/problems/remove-methods-from-project/
 *
 * Approach: Graph traversal using BFS from node k to mark all reachable methods
 * as suspicious. We also track in-degrees to detect if any suspicious node is
 * reachable from a non-suspicious node (indicating an external dependency that
 * prevents removal). If any suspicious node still has a positive in-degree after
 * BFS traversal, no methods can be removed; otherwise return all non-suspicious nodes.
 *
 * Time Complexity: O(N + E) where N is the number of methods and E is the number
 * of invocations, as we traverse all edges once during BFS.
 *
 * Space Complexity: O(N + E) for the adjacency list, in-degree array, BFS queue,
 * and bitset tracking suspicious nodes.
 *
 * Runtime: 159 ms | Memory: 302.5 MB
 */

constexpr int MAXN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDegree(n, 0);

        bitset<MAXN> suspicious;

        for (const auto& inv : invocations) {
            edges[inv[0]].push_back(inv[1]);
            inDegree[inv[1]]++;
        }

        queue<int> q;
        q.push(k);

        suspicious.set(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                inDegree[v]--;

                if (!suspicious.test(v)) {
                    q.push(v);
                    suspicious.set(v);
                }
            }
        }

        bool canRemoveAll = true;
        vector<int> remaining;

        for (int i = 0; i < n; i++) {
            if (suspicious.test(i) && inDegree[i] > 0) {
                canRemoveAll = false;
                break;
            } else if (!suspicious.test(i)) {
                remaining.push_back(i);
            }
        }

        if (!canRemoveAll) {
            vector<int> allNodes(n);
            iota(allNodes.begin(), allNodes.end(), 0);
            return allNodes;
        }

        return remaining;
    }
};
