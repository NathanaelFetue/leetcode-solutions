/*
 * Problem #75 - Sort Colors
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sort-colors/
 *
 * Approach: Dutch National Flag Algorithm (3-way partitioning).
 * Three pointers (low, mid, high) are used to partition the array in a single pass.
 * Elements less than 1 (0s) are swapped to the front, elements greater than 1 (2s) are swapped to the end, and 1s settle in the middle naturally.
 * When a 2 is swapped from the high pointer, mid is not incremented since the swapped-in element is still unprocessed.
 *
 * Time Complexity: O(n) - single pass through the array with at most n iterations.
 * Space Complexity: O(1) - sorting is done in-place with only three integer pointers.
 *
 * Runtime: 0 ms
 * Memory: 11.7 MB
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
                // ne pas incrémenter mid car on vient de ramener un inconnu
            }
        }
    }
};
