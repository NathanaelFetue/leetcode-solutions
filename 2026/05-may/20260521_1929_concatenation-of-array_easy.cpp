/*
 * Problem 1929: Concatenation of Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/concatenation-of-array/
 *
 * Approach: In-place array extension by iterating through the original n elements
 * and appending each to the end of the same vector. By storing the original size n
 * before modification, we avoid re-processing newly added elements during iteration.
 *
 * Time Complexity: O(n) - single pass through the original n elements to append each once.
 * Space Complexity: O(1) extra space - concatenation is done in-place on the input vector
 * (output array of size 2n is required by the problem, not counted as extra space).
 *
 * Runtime: 0 ms
 * Memory: 17.1 MB
 */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i < n; i++ ){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
