/*
 * Problem #704 - Binary Search
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-search/
 *
 * Approach/Algorithm:
 * Uses the STL lower_bound function to perform binary search on the sorted array.
 * lower_bound returns an iterator to the first element not less than the target.
 * If the iterator is valid and points to the target value, we return its index; otherwise -1.
 *
 * Time Complexity: O(log n) - binary search halves the search space each iteration.
 * Space Complexity: O(1) - no additional data structures are used; only a single iterator.
 *
 * Runtime: 0 ms
 * Memory: 31.3 MB
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);

        if(it != nums.end() && *it==target) return it- nums.begin();
        else return -1;
    }
};
