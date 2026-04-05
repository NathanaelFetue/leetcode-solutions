/*
 * Problem 3432: Count Partitions with Even Sum Difference
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 *
 * Approach: Prefix Sum
 * Build a prefix sum array to efficiently compute the sum of any subarray.
 * For each valid partition index j (1 to n-1), the left sum is prefix[j-1] and
 * the right sum is totalSum - prefix[j-1]. The difference is totalSum - 2*prefix[j-1].
 * Count partitions where this difference is even (divisible by 2).
 *
 * Time Complexity: O(n) - two linear passes: one to build prefix sums, one to count valid partitions.
 * Space Complexity: O(n) - additional prefix sum array of size n.
 *
 * Runtime: 0 ms
 * Memory: 23.2 MB
 */

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n,0);
        for (int i=0; i<n; i++) {
            if (i==0) {
                prefix[i] = nums[i];
                continue;
            }
            prefix[i] += prefix[i-1]+nums[i];
        }
        int diff =0 , coup =0;
        for (int j =1 ;j<n; j++) {
            diff = prefix[n-1] - 2*prefix[j-1];
            if (diff%2 == 0) coup++;  
        }
        return coup;

    }
};
