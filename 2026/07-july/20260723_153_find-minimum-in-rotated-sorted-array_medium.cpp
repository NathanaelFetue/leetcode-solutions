/*
 * Problem #153: Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * Approach: Binary Search
 * The algorithm uses binary search to locate the rotation pivot where the minimum element resides.
 * At each step, if the middle element is greater than the rightmost element, the minimum must lie
 * in the right half (left = mid + 1); otherwise, the minimum is in the left half including mid
 * (right = mid). The search narrows until left == right, pointing to the minimum.
 *
 * Time Complexity : O(log n) - the search space is halved at each iteration.
 * Space Complexity: O(1) - only a constant number of pointers are used.
 *
 * Runtime : 0 ms
 * Memory  : 14.2 MB
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right])
                left = mid + 1;  
            else
                right = mid; 
        }
        
        return nums[left];
    }
};
