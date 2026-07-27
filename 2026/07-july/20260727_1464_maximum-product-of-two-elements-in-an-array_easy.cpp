/*
 * Problem 1464: Maximum Product of Two Elements in an Array (Easy)
 * https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 *
 * Approach: Sort the array in descending order so the two largest elements
 * appear at indices 0 and 1. The answer is simply (nums[0]-1)*(nums[1]-1),
 * as the problem requires subtracting 1 from each chosen element before multiplying.
 *
 * Time Complexity: O(n log n) — dominated by sorting the array of n elements.
 * Space Complexity: O(1) — sorting is done in-place with no extra data structures.
 *
 * Runtime: 0 ms
 * Memory: 13.4 MB
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end() , greater<int>());

        return (nums[0]-1)*(nums[1]-1);
    }
};
