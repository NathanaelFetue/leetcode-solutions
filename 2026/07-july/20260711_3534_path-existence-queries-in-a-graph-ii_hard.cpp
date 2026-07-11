/*
 * Problem 3534 - Path Existence Queries in a Graph II
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
 *
 * Approach: Binary Lifting on Sorted Indices
 * Nodes are sorted by value and for each node we precompute the leftmost reachable
 * node (in sorted order) within maxDiff. Binary lifting (sparse table) is built so
 * that f[i][j] stores the leftmost node reachable from node i in 2^j jumps. For
 * each query, we greedily consume the largest jumps possible moving left toward the
 * target, counting steps, then check if one more jump reaches it.
 *
 * Time Complexity: O((n + q) log n)
 *   - O(n log n) for sorting and building the sparse table
 *   - O(q log n) for answering each query with binary lifting
 *
 * Space Complexity: O(n log n) for the sparse table
 *
 * Runtime: 374 ms | Memory: 395.6 MB
 */

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<int> idx(n), pos(n), res;
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return nums[a] < nums[b]; });
        for (int i = 0; i < n; i++) {
            pos[idx[i]] = i;
        }

        int m = 32 - __builtin_clz(n);
        vector<vector<int>> f(n, vector<int>(m));

        for (int i = 0, left = 0; i < n; i++) {
            while (nums[idx[i]] - nums[idx[left]] > maxDiff) left++;
            f[i][0] = left;
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }

        for (auto& q : queries) {
            auto [x, y] = pair(pos[q[0]], pos[q[1]]);
            if (x > y) {
                swap(x, y);
            }
            if (x == y) {
                res.push_back(0);
                continue;
            }

            int step = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (f[y][i] > x) {
                    y = f[y][i];
                    step += 1 << i;
                }
            }

            res.push_back(f[y][0] <= x ? step + 1 : -1);
        }
        return res;
    }
};
