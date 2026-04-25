/*
 * Problem #136 - Single Number (Easy)
 * LeetCode URL: https://leetcode.com/problems/single-number/
 *
 * Approach/Algorithm:
 * For each element at index i, perform a linear scan over all other elements
 * using XOR to check if a matching pair exists (XOR of two equal numbers is 0).
 * If no match is found, the current element is the single (unpaired) number.
 *
 * Time Complexity: O(n^2) - for each of the n elements, we scan all other n elements,
 * resulting in a nested loop with quadratic time complexity.
 *
 * Space Complexity: O(1) - only a constant number of extra variables are used,
 * regardless of the input size.
 *
 * Runtime: 520 ms
 * Memory: 20.5 MB
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        for (i; i < nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) continue;
                if ((nums[i] ^ nums[j]) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        return nums[i];
    }
};
