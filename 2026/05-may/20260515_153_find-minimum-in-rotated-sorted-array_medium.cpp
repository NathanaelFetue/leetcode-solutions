/*
 * Problem #153 - Find Minimum in Rotated Sorted Array (Medium)
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 *
 * Approach: Binary Search on Rotated Array
 * We use binary search by comparing the middle element with the rightmost element.
 * If nums[mid] > nums[right], the minimum must lie in the right half, so we move left to mid+1.
 * Otherwise, the minimum is at mid or in the left half, so we move right to mid.
 * The search converges when left == right, pointing to the minimum element.
 *
 * Time Complexity : O(log n) - binary search halves the search space each iteration
 * Space Complexity : O(1) - only constant extra variables used
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
                left = mid + 1;  // min dans la partie droite
            else
                right = mid;     // min est mid ou à gauche
        }
        
        return nums[left];
    }
};
