/*
 * Binary Prefix Divisible By 5
 * Difficulty: Easy
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/
 *
 * Approach: Iterative modular arithmetic on running binary value.
 * For each bit, update the current number as (x * 2 + bit) % 5 to simulate
 * appending a binary digit, keeping only the remainder mod 5 to avoid overflow.
 *
 * Time Complexity:  O(n) - single pass through the input array
 * Space Complexity: O(n) - output boolean array of size n
 *
 * Runtime : 0 ms
 * Memory  : 18.5 MB
 */

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int x = 0;
        for (int bit : nums) {
            x = (x * 2 + bit) % 5;
            answer.push_back(x == 0);
        }
        return answer;
    }
};
