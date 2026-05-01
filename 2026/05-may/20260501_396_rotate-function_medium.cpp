/*
 * Problem #396 - Rotate Function
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotate-function/
 *
 * Approach: Mathematical recurrence relation between consecutive rotations.
 * F(k) can be derived from F(k-1) using the relation: F(k) = F(k-1) + sum(nums) - n * nums[n-k].
 * This avoids recomputing the full weighted sum for each rotation by leveraging the shift pattern.
 *
 * Time Complexity: O(n) - single pass to compute initial F(0) and sum, then one more pass for all rotations.
 * Space Complexity: O(1) - only a constant number of variables are used beyond the input.
 *
 * Runtime: 0 ms
 * Memory: 99.6 MB
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sumVal = accumulate(nums.begin(), nums.end(), 0);
        
        int fk = 0;
        for (int i = 0; i < n; i++) fk += i * nums[i];
        
        int maxVal = fk;
        for (int k = 1; k < n; k++) {
            fk = fk + sumVal - n * nums[n - k];
            maxVal = max(maxVal, fk);
        }
        return maxVal;
    }
};
