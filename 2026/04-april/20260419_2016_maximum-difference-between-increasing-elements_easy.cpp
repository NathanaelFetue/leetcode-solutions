/*
 * Problem 2016: Maximum Difference Between Increasing Elements
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 *
 * Approach: Two-pointer sliding window technique.
 * A slow pointer (f) tracks the current minimum candidate, and a fast pointer (ff) scans ahead
 * to find the largest valid increasing difference. When ff reaches the end, f advances and ff resets.
 *
 * Time Complexity: O(n^2) in the worst case due to the nested traversal pattern where
 * ff resets to f+1 each time it reaches the end of the array.
 *
 * Space Complexity: O(1) — only a constant number of integer variables are used
 * regardless of input size.
 *
 * Runtime: 7 ms
 * Memory: 11.7 MB
 */

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int best =0 , f=0, ff=1; //f for fast, ff for faster;
        while(f<n-1) {
            if(nums[ff] > nums[f]){
                best = max(best , nums[ff] - nums[f]);
            }
            if(ff == n-1) {
                f++;
                ff =f;
            }
            ff++;
        }
        if (best==0) return -1;
        return best;
    }
};
