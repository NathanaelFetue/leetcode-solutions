/*
 * Problem 3653: XOR After Range Multiplication Queries I
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
 *
 * Approach:
 * For each query (l, r, k, v), iterate over indices from l to r with step k,
 * multiplying each element by v modulo 1e9+7. After processing all queries,
 * compute the XOR of all elements in the modified array and return the result.
 *
 * Time Complexity: O(Q * N/K + N) where Q is the number of queries, N is the
 * array size, and K is the step size per query. In the worst case (K=1) this
 * becomes O(Q * N).
 *
 * Space Complexity: O(1) extra space, as modifications are done in-place on
 * the input array with only a few scalar variables used.
 *
 * Runtime: 48 ms
 * Memory: 158.1 MB
 */

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            int ki = query[2];
            int vi = query[3];

            for (int idx = li; idx <= ri; idx += ki) {
                long long current = nums[idx];
                nums[idx] = (current * vi) % MOD;
            }
        }
        int result = 0;
        for (int val : nums) {
            result ^= val;
        }
        return result;
    }
};
