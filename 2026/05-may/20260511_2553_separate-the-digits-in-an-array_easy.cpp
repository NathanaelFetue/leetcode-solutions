/*
 * Problem 2553: Separate the Digits in an Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/separate-the-digits-in-an-array/
 *
 * Approach: For each integer in the input array, convert it to its string
 * representation, then iterate over each character and extract the digit
 * by subtracting '0', appending each digit to the result vector in order.
 *
 * Time Complexity: O(n * d) where n is the number of elements in nums and
 * d is the average number of digits per number (at most 5 for typical
 * constraints), effectively O(n) in practice.
 *
 * Space Complexity: O(n * d) for the output vector storing all individual
 * digits, with capacity pre-reserved to avoid repeated reallocations.
 *
 * Runtime: 4 ms
 * Memory: 15.2 MB
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size() * 5);
        
        for(int num : nums) {
            string s = to_string(num);
            for(char c : s) {
                res.push_back(c - '0');
            }
        }
        return res;
    }
};
