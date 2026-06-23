/*
 * Problem #3699 - Number of ZigZag Arrays I
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/number-of-zigzag-arrays-i/
 *
 * Approach: Dynamic Programming with prefix/suffix sums over value ranges.
 * dp0[y] = number of zigzag arrays ending with value y where last step was descending (or start),
 * dp1[y] = number ending with value y where last step was ascending.
 * At each position, use prefix sums of dp1 for transitions requiring a smaller next value,
 * and suffix sums of dp0 for transitions requiring a larger next value, enabling O(m) per step.
 *
 * Time Complexity: O(n * m) where m = r - l + 1 (value range size) and n is array length.
 * Each of the n-1 transitions processes the m possible values in linear time via prefix/suffix scans.
 *
 * Space Complexity: O(m) — only a fixed number of vectors of size m (and m+1) are allocated,
 * with in-place swaps avoiding any extra allocation per iteration.
 *
 * Runtime: 723 ms | Memory: 25.8 MB
 */

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        // Pré-allouer une seule fois
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

            swap(dp0, ndp0); // O(1) pas de copie
            swap(dp1, ndp1);
        }

        long long ans = 0;
        for (int x = 0; x < m; x++)
            ans = (ans + dp0[x] + dp1[x]) % MOD;

        return ans;
    }
};
