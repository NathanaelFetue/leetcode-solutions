/*
 * Problem #3699: Number of ZigZag Arrays I
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/number-of-zigzag-arrays-i/
 *
 * Approach: Dynamic Programming with Prefix/Suffix Sum Optimization
 * dp0[x] stores the number of valid zigzag arrays of length i ending at value (l+x) where the last step was descending (or it is the first element).
 * dp1[x] similarly tracks arrays where the last step was ascending. For each new element y, ndp0[y] sums all dp1[x] where x > y (strictly less, via prefix sum), and ndp1[y] sums all dp0[x] where x < y (via suffix sum), reducing the naive O(m^2) per step to O(m).
 *
 * Time Complexity: O(n * m) where m = r - l + 1 (range size) and n is the array length.
 *   Each of the n-1 transitions processes m elements with O(1) work each using prefix/suffix arrays.
 *
 * Space Complexity: O(m) for the dp arrays, prefix/suffix arrays, and temporary buffers.
 *
 * Runtime: 732 ms | Memory: 25.8 MB
 */

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<long long> dp0(m, 1), dp1(m, 1);
        vector<long long> ndp0(m), ndp1(m);
        vector<long long> pre(m + 1), suf(m + 1);

        for (int i = 1; i < n; i++) {
            fill(ndp0.begin(), ndp0.end(), 0);
            fill(ndp1.begin(), ndp1.end(), 0);

            pre[0] = 0;
            for (int x = 0; x < m; x++)
                pre[x + 1] = (pre[x] + dp1[x]) % MOD;

            suf[m] = 0;
            for (int x = m - 1; x >= 0; x--)
                suf[x] = (suf[x + 1] + dp0[x]) % MOD;

            for (int y = 0; y < m; y++) {
                ndp0[y] = pre[y];
                ndp1[y] = suf[y + 1];
            }

            swap(dp0, ndp0);
            swap(dp1, ndp1);
        }

        long long ans = 0;
        for (int x = 0; x < m; x++)
            ans = (ans + dp0[x] + dp1[x]) % MOD;

        return ans;
    }
};
