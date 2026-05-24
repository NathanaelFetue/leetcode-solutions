/*
 * Problem #1340 - Jump Game V (Hard)
 * https://leetcode.com/problems/jump-game-v/
 *
 * Approach: Memoized DFS (Top-Down Dynamic Programming)
 * From each index, we attempt to jump up to d steps left and right, but only to indices
 * with strictly smaller values (stopping as soon as a taller or equal bar is encountered).
 * The result for each index is cached in a dp array to avoid redundant recomputation.
 * We iterate over all indices and take the maximum reachable count across all starting points.
 *
 * Time Complexity: O(n * d) - each of the n indices is computed once, exploring up to 2d neighbors.
 * Space Complexity: O(n) - dp memoization array of size n plus O(n) recursion call stack in the worst case.
 *
 * Runtime: 15 ms
 * Memory: 19.1 MB
 */

class Solution {
    vector<int> dp;

    int dfs(vector<int>& arr, int i, int d) {
        if (dp[i] != -1) return dp[i];

        dp[i] = 1;
        for (int x = 1; x <= d && i + x < arr.size(); x++) {
            if (arr[i + x] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + dfs(arr, i + x, d));
        }

        for (int x = 1; x <= d && i - x >= 0; x++) {
            if (arr[i - x] >= arr[i]) break;
            dp[i] = max(dp[i], 1 + dfs(arr, i - x, d));
        }

        return dp[i];
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        dp.assign(arr.size(), -1);

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            ans = max(ans, dfs(arr, i, d));

        return ans;
    }
};
