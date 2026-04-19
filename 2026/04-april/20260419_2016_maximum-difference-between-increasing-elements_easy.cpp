/*
 * Problem #2016: Maximum Difference Between Increasing Elements
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 *
 * Approach: Single-pass greedy scan tracking the minimum element seen so far.
 * For each element, if it is greater than the current minimum, compute the difference
 * and update the best result. Otherwise, update the running minimum.
 *
 * Time Complexity: O(n) - single linear scan through the array of size n.
 * Space Complexity: O(1) - only a constant number of variables are used.
 *
 * Runtime: 0 ms
 * Memory: 11.9 MB
 */

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int best = -1, smallest = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > smallest) {
                best = max(best, nums[i] - smallest);
            } else {
                smallest = nums[i];
            }
        }
        return best;
    }
};
