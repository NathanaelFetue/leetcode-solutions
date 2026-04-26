/*
 * Problem: Unique Paths
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/unique-paths/
 *
 * Approach: Combinatorics (Math)
 * The robot must make exactly (m-1) moves right and (n-1) moves down, totaling N = m+n-2 steps.
 * The number of unique paths equals C(N, k) where k = min(m-1, n-1), computed iteratively
 * using the multiplicative formula to avoid overflow and stay within integer bounds.
 *
 * Time Complexity: O(min(m, n)) - one loop over the smaller dimension to compute C(N, k).
 * Space Complexity: O(1) - only a constant number of variables are used.
 *
 * Runtime: 0 ms
 * Memory: 7.7 MB
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int k = min(m - 1, n - 1);

        long long res = 1;
        for(int i = 1; i <= k; i++) {
            res = res * (N - i + 1) / i;
        }
        return (int)res;
    }
};
