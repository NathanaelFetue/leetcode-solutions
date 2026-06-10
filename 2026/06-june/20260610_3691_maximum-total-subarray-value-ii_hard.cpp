/*
 * Problem #3691 - Maximum Total Subarray Value II
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/maximum-total-subarray-value-ii/
 *
 * Approach: Sparse Table + Greedy Max-Heap
 * Build a sparse table for O(1) range maximum and range minimum queries. Use a max-heap initialized with entries (max - min) for all subarrays starting at each index l and ending at n-1. Greedily extract the top k subarray values by always popping the best candidate and pushing a shrunk version (r-1) to explore next-best subarrays.
 *
 * Time Complexity: O((n + k) log n) - O(n log n) to build the sparse table and initialize the heap with n entries, O(k log n) for k heap operations.
 * Space Complexity: O(n log n) - for the two sparse tables storing max and min values.
 *
 * Runtime: 620 ms
 * Memory: 327.1 MB
 */

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int logn = 32 - __builtin_clz(n);
        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));
        for (int i = 0; i < n; i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }
        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };
        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };
        priority_queue<tuple<int, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
        }
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
            }
        }
        return ans;
    }
};
