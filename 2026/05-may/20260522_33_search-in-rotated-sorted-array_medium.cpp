/*
 * Problem #33 - Search in Rotated Sorted Array (Medium)
 * LeetCode URL: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Approach: Modified Binary Search
 * The array is split into two sorted halves by the rotation point. At each step, we
 * determine which half is sorted by comparing nums[left] with nums[mid], then check
 * if the target lies within the sorted half to decide which side to continue searching.
 *
 * Time Complexity: O(log n)
 *   - Binary search halves the search space at every iteration.
 *
 * Space Complexity: O(1)
 *   - Only a constant number of pointers are used; no extra data structures.
 *
 * Runtime: 0 ms
 * Memory: 15.1 MB
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
           
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
