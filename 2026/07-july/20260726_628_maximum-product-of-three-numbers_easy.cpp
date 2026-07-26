/*
 * Problem #628 - Maximum Product of Three Numbers (Easy)
 * https://leetcode.com/problems/maximum-product-of-three-numbers/
 *
 * Approach: Sort the array and evaluate two candidate combinations.
 * The maximum product of three numbers is either the product of the three largest
 * elements, or the product of the two smallest (most negative) elements and the largest.
 * Sorting allows direct access to extremes via indices in O(1) after sorting.
 *
 * Time Complexity: O(n log n) — dominated by the sort step.
 * Space Complexity: O(1) — only a constant number of variables used beyond the input.
 *
 * Runtime : 0 ms
 * Memory  : 31.4 MB
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Soit les 3 plus grands
        // Soit les 2 plus petits * le plus grand
        return max(
            nums[n-1] * nums[n-2] * nums[n-3],
            nums[0] * nums[1] * nums[n-1]
        );
    }
};
