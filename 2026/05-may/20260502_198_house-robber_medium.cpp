/*
 * Problem #198: House Robber (Medium)
 * https://leetcode.com/problems/house-robber/
 *
 * Approach: Bottom-up dynamic programming with constant space optimization.
 * At each house, the optimal choice is either to skip it (take the previous best)
 * or rob it (add its value to the best result two houses back).
 * We track only the two most recent DP states instead of a full array.
 *
 * Time Complexity: O(n) — single linear pass through all houses.
 * Space Complexity: O(1) — only two integer variables used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 10 MB
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
