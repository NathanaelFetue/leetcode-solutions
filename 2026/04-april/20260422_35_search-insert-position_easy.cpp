/*
 * Problem #35: Search Insert Position (Easy)
 * URL: https://leetcode.com/problems/search-insert-position/
 *
 * Approach: Binary Search
 * Perform classic binary search on the sorted array. At each step, compare the
 * middle element with the target and narrow the search range accordingly. If the
 * target is not found, the left pointer (deb) naturally lands at the correct
 * insertion position once the loop exits.
 *
 * Time Complexity : O(log n) - the search space is halved at each iteration.
 * Space Complexity : O(1) - only a constant number of variables are used.
 *
 * Runtime : 0 ms
 * Memory  : 13.5 MB
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int deb = 0, end = nums.size() - 1;
        while (deb <= end) {
            int mid = deb + (end - deb) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) deb = mid + 1;
            else end = mid - 1;
        }
        return deb;
    }
};
