/*
 * Problem 3622: Check Divisibility by Digit Sum and Product
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
 *
 * Approach:
 * The key insight is to decompose the integer into its constituent digits using base-10 arithmetic to compute their sum and product concurrently. This technique of iterative digit extraction via modulo and integer division avoids the overhead of string conversion, processing the number from least significant to most significant digit in a single pass. By accumulating the running sum and product, we can directly compute the divisor (sum + product) and check divisibility using the modulo operator. This guarantees correctness as it mathematically isolates each digit to construct the required terms before performing the final divisibility check.
 *
 * Time Complexity: O(log10(N)) — the number of iterations is directly proportional to the number of digits in n, which is bounded by log base 10 of n.
 * Space Complexity: O(1) — only a few scalar variables are used to store the digit sum, product, and temporary states, requiring constant auxiliary memory.
 *
 * Runtime: 0 ms | Memory: 7.9 MB
 */

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0, mul=1;
        int tmp = n , tmp2;
        while(tmp>0){
            tmp2 = tmp%10;
            sum += tmp2; mul *=tmp2;
            tmp /=10;
        }
        return (n%(sum+mul) == 0);

    }
};
