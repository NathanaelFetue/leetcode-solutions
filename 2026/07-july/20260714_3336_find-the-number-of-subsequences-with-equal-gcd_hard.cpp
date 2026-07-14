/*
 * Problem #3336: Find the Number of Subsequences With Equal GCD
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/
 *
 * Approach: Top-down dynamic programming with memoization.
 * At each index, we decide to skip the element or assign it to one of two subsequences.
 * We track the running GCD of each subsequence, counting pairs where both GCDs are equal and non-zero at the end.
 *
 * Time Complexity: O(n * M^2 * log(M)) where n is the array length and M is the max value (200).
 * The log(M) factor comes from the GCD computation at each state transition.
 *
 * Space Complexity: O(n * M^2) for the 3D memoization table of size 200 x 201 x 201.
 *
 * Runtime: 1139 ms
 * Memory: 58 MB
 */

class Solution {
    const int mod = 1e9 + 7;
    int dp[200][201][201];
public:
    int solve(int i, vector<int> &nums, int first, int second){
        // first == gcd of first subsequence till now
        // second = gcd of second subsequence till now

        if(i == nums.size()){
            return (first && second) && (first == second);
        }
        
        if(dp[i][first][second] != -1) return dp[i][first][second];
        
        int skip = solve(i + 1, nums, first, second);

        int take1 = solve(i + 1, nums, __gcd(first, nums[i]), second);

        int take2 = solve(i + 1, nums, first, __gcd(second, nums[i]));
        
        return dp[i][first][second] = (0LL + skip + take1 + take2) % mod;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, 0);
    }
};
