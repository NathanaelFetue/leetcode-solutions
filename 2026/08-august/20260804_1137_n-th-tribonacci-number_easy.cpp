/*
 * Problem #1137 - N-th Tribonacci Number (Easy)
 * URL: https://leetcode.com/problems/n-th-tribonacci-number/
 *
 * Approach: Iterative Bottom-Up Dynamic Programming (Space Optimized)
 * Handle base cases directly for n=0 (return 0) and n<=2 (return 1).
 * For n>=3, iteratively compute each tribonacci number by summing the
 * previous three values, rolling the variables forward until reaching n.
 *
 * Time Complexity: O(n) - single loop from 3 to n, each iteration O(1).
 * Space Complexity: O(1) - only three integer variables used regardless of n.
 *
 * Runtime: 0 ms
 * Memory: 7.8 MB
 */

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if (n <=2) return 1;
        int t0=0 , t1=1 , t2=1;

        for(int i=3; i<=n; i++){
            int next = t0+t1+t2;
            t0 = t1;
            t1 = t2;
            t2= next;
        }
        return t2;
    }
};
