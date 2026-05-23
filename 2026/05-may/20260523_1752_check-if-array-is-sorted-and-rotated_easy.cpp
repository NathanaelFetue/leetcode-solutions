/*
 * Problem #1752: Check if Array Is Sorted and Rotated
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 *
 * Approach: Count Descending Breakpoints (Circular Traversal)
 * Iterate through the array circularly using modulo indexing and count the number of positions
 * where nums[i] > nums[(i+1) % n] (i.e., a descending step occurs). A valid sorted-and-rotated
 * array can have at most one such breakpoint; more than one means it cannot be a rotation of a
 * sorted array.
 *
 * Time Complexity: O(n) — single pass through all n elements.
 * Space Complexity: O(1) — only a counter variable is used, no extra data structures.
 *
 * Runtime: 0 ms
 * Memory: 11.2 MB
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};
