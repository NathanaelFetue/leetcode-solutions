/*
 * Find Minimum Operations to Make All Elements Divisible by Three
 * Difficulty: Easy
 * https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
 *
 * Approach: Linear scan with modulo check.
 * For each element, check if it is divisible by three using the modulo operator.
 * Any element not divisible by three requires exactly one operation (either +1 or -1), so simply count those elements.
 *
 * Time Complexity: O(n) - single pass through the array.
 * Space Complexity: O(1) - only a counter variable is used.
 *
 * Runtime: 0 ms
 * Memory: 23.1 MB
 */

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int n : nums) {
            if (n % 3 != 0) ops++;
        }
        return ops;
    }
};
