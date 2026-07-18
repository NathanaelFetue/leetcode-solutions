/*
 * Problem 1979: Find Greatest Common Divisor of Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 *
 * Approach: Find the minimum and maximum elements of the array, then compute
 * their GCD using the built-in __gcd function (Euclidean algorithm). The GCD
 * of the entire array's smallest and largest values is the required answer.
 *
 * Time Complexity: O(n + log(min(a,b))) where n is the array size for finding
 * min/max, and log(min(a,b)) for the Euclidean GCD computation.
 *
 * Space Complexity: O(1) - only two integer variables are used regardless
 * of input size.
 *
 * Runtime: 0 ms
 * Memory: 16.2 MB
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin() , nums.end());
        int large = *max_element(nums.begin(), nums.end());

        return __gcd(small, large);;
    }
};
