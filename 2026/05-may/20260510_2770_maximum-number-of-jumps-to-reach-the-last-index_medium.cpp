/*
 * Problem #2770: Maximum Number of Jumps to Reach the Last Index (Medium)
 * https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
 *
 * Approach: Bottom-up Dynamic Programming
 * dp[j] stores the maximum number of jumps to reach index j from index 0.
 * For each index j, iterate over all prior indices i and check if the jump condition
 * (-target <= nums[j] - nums[i] <= target) is satisfied. If dp[i] is reachable,
 * update dp[j] = max(dp[j], dp[i] + 1). Unreachable indices remain -1.
 *
 * Time Complexity: O(n^2) — two nested loops over all index pairs (i, j).
 * Space Complexity: O(n) — dp array of size n to store max jumps per index.
 *
 * Runtime: 10 ms
 * Memory: 68.4 MB
 */

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = 0;

        for(int j=1; j<n; j++){
            for(int i=0; i<j;i++) {
                if((-target <= nums[j]-nums[i]  && nums[j]-nums[i] <= target)){
                    if(dp[i] != -1) {
                        dp[j] = max(dp[j] , dp[i]+1);
                    }
                }
            }
        };
        return dp[n-1];
    }
};
