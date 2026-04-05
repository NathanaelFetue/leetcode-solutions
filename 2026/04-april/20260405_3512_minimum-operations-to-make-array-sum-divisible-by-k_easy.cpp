/*
 * Problem 3512: Minimum Operations to Make Array Sum Divisible by K
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 *
 * Approach: Compute the total sum of the array, then determine how many
 * decrements are needed to make it divisible by K. If K exceeds the sum,
 * return the sum itself; otherwise, return sum % K (the remainder when
 * divided by K represents the minimum operations needed).
 *
 * Time Complexity: O(n) — single pass via accumulate to compute the sum.
 * Space Complexity: O(1) — only a single integer variable is used.
 *
 * Runtime: 0 ms
 * Memory: 45.3 MB
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if (k > sum) return sum;
        return sum%k;
    }
};
