/*
 * Problem 3512: Minimum Operations to Make Array Sum Divisible by K
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
 *
 * Approach: Compute the total sum of the array, then determine how many
 * operations (each decrementing the sum by 1) are needed to make it divisible
 * by K. If the sum is already divisible by K, return 0; if K exceeds the sum,
 * return the entire sum; otherwise return sum % K as the remainder to eliminate.
 *
 * Time Complexity: O(n) - single pass via accumulate to compute the array sum.
 * Space Complexity: O(1) - only a constant amount of extra space is used.
 *
 * Runtime: 0 ms
 * Memory: 45.3 MB
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if (k > sum) return sum;
        if (sum % k == 0) {
            return 0;
        } else return sum%k;
    }
};
