/*
 * Problem #26 - Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Approach: Two-pointer in-place overwrite technique.
 * A write pointer k tracks the position for the next unique element, starting at 1.
 * We iterate through the array and whenever a new unique element is found (differs from its predecessor), it is written to position k and k is incremented.
 *
 * Time Complexity: O(n) - single linear pass through the array of n elements.
 * Space Complexity: O(1) - the deduplication is performed in-place with only a constant amount of extra variables.
 *
 * Runtime: 0 ms
 * Memory: 22.6 MB
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
