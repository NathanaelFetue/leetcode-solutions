/*
 * Problem #1979: Find Greatest Common Divisor of Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
 *
 * Approach:
 * Find the minimum and maximum elements of the array using STL min_element
 * and max_element. Then apply the built-in __gcd function on these two values,
 * since the GCD of the entire array's smallest and largest elements is the answer.
 *
 * Time Complexity: O(n) — scanning the array twice to find min and max,
 * plus O(log(min(small, large))) for the Euclidean GCD computation.
 *
 * Space Complexity: O(1) — only two integer variables are used regardless
 * of input size.
 *
 * Runtime: 0 ms | Memory: 16.1 MB
 */

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin() , nums.end());
        int large = *max_element(nums.begin(), nums.end());

        return __gcd(small, large);;
    }
};
