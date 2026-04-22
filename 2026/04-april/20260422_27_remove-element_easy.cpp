/*
 * Problem #27 - Remove Element (Easy)
 * LeetCode URL: https://leetcode.com/problems/remove-element/
 *
 * Approach: Two-pointer / in-place overwrite technique.
 * Iterate through the array with index i; whenever the current element does not
 * equal val, write it to position k and advance k. This effectively compacts all
 * non-val elements to the front of the array without using extra space.
 *
 * Time Complexity: O(n) - single pass through the array of n elements.
 * Space Complexity: O(1) - in-place modification, only a counter variable used.
 *
 * Runtime : 0 ms
 * Memory  : 11.6 MB
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) nums[k++] = nums[i];
        }
        return k;
    }
};
