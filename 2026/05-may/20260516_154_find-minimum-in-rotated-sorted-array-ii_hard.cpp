/*
 * Problem #154: Find Minimum in Rotated Sorted Array II (Hard)
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *
 * Approach: Modified Binary Search
 * Use binary search comparing the mid element to the right boundary to determine
 * which half contains the minimum. When duplicates are encountered (nums[mid] == nums[right]),
 * the right pointer is decremented by one to safely shrink the search space without
 * skipping the minimum, handling the ambiguity duplicates introduce.
 *
 * Time Complexity: O(log n) average, O(n) worst case (all duplicate elements)
 *   - Each iteration halves the search space except when duplicates force a linear step.
 * Space Complexity: O(1) - only a constant number of pointers are used.
 *
 * Runtime : 0 ms
 * Memory  : 16.3 MB
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right--; // doublon > on ne sait pas, on réduit prudemment
        }
        
        return nums[left];
    }
};
