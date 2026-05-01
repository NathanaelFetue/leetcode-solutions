/*
 * Problem #396 - Rotate Function
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotate-function/
 *
 * Approach: Mathematical Recurrence / Prefix Sum Optimization
 * First compute F(0) by directly summing i*nums[i]. Then observe that each rotation
 * F(k) = F(k-1) + sum(nums) - n*nums[n-1-(k-1)], allowing O(1) transition between
 * rotations by reusing the previous value and the total array sum.
 *
 * Time Complexity: O(n) — one pass to compute F(0) and array sum, one pass to iterate
 * through all n rotations using the recurrence relation.
 *
 * Space Complexity: O(1) — only a constant number of variables are used regardless
 * of input size.
 *
 * Runtime: 7 ms | Memory: 99.7 MB
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return 0;
        int fk=0 , fk1 = 0 , maxVal = INT_MIN;
        for(int i =0; i<n; i++) {
            fk += nums[i]*i;
        }
        int sumVal = accumulate(nums.begin() , nums.end() , 0);
        for(int i =0; i<n; i++) {
            fk1 = fk + sumVal - n*nums[n-1-i];
            fk = fk1;
            maxVal = max(maxVal , fk); 
        }
        return maxVal;
    }
};
