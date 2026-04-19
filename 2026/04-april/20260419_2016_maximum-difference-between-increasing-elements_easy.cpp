/*
 * Problem #2016: Maximum Difference Between Increasing Elements
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
 *
 * Approach: Two-pointer sliding window traversal.
 * A slow pointer (f) anchors the minimum candidate, while a fast pointer (ff) scans
 * ahead to find the maximum valid difference where nums[ff] > nums[f]. Whenever ff
 * reaches the end, f advances and ff resets, ensuring all pairs are considered.
 * Returns -1 if no valid increasing pair exists (best remains 0).
 *
 * Time Complexity: O(n^2) in the worst case due to nested pointer resets,
 * though typical traversal visits each pair once per anchor position.
 * Space Complexity: O(1) — only a constant number of variables are used.
 *
 * Runtime: 7 ms | Memory: 11.7 MB
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
