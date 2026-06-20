/*
 * Problem #1840 - Maximum Building Height (Hard)
 * https://leetcode.com/problems/maximum-building-height/
 *
 * Approach: Constraint Propagation with Greedy Between Restricted Pairs
 * First, add sentinels for building 1 (height 0) and building n (unconstrained up to n-1),
 * then propagate height limits left-to-right and right-to-left to enforce adjacency rules.
 * For each consecutive restricted pair, compute the tallest reachable peak between them using
 * the formula: (gap + leftHeight + rightHeight) / 2, and take the global maximum.
 *
 * Time Complexity: O(m log m) — dominated by sorting m restriction entries.
 * Space Complexity: O(m) — in-place modification of the restrictions array with two sentinel entries.
 *
 * Runtime: 95 ms
 * Memory: 106.7 MB
 */

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        if (r.back()[0] != n) {
            r.push_back({n, n - 1});
        }

        int m = r.size();
        for (int i = 1; i < m; ++i) {
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }
        for (int i = m - 2; i >= 0; --i) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }

        return ans;
    }
};
