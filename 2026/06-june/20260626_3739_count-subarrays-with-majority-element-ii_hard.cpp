/*
 * Problem #3739: Count Subarrays With Majority Element II
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
 *
 * Approach: Prefix Sum with Balance Counter
 * Transform the array into +1 (target) and -1 (non-target) values and track a running
 * balance (cnt). A subarray ending at index i has a majority target element if the
 * balance difference between the end and start is positive (> 0), meaning more targets
 * than non-targets. We maintain a frequency array (pre) of prefix balances, and a
 * running sum (presum) of how many previous balances are strictly less than the current
 * one, adding presum to the answer at each step.
 *
 * Time Complexity: O(n) - single pass through the array with O(1) operations per element
 * Space Complexity: O(n) - prefix frequency array of size 2n+1 to cover all balance values
 *
 * Runtime: 6 ms
 * Memory: 95.5 MB
 */

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0, presum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
};
