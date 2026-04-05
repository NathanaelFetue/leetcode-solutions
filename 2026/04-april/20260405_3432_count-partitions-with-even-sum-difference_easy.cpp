/*
 * Problem #3432: Count Partitions with Even Sum Difference (Easy)
 * URL: https://leetcode.com/problems/count-partitions-with-even-sum-difference/
 *
 * Approach: Prefix Sum with Parity Check
 * Compute the total sum of the array, then iterate through all valid partition points
 * (indices 0 to n-2), maintaining a running left sum. For each partition, the difference
 * (right - left) = total - 2*left, which is even if and only if (total - 2*left) % 2 == 0.
 * Since 2*left is always even, the parity of the difference equals the parity of total,
 * meaning we simply count partitions where total is even.
 *
 * Time Complexity: O(n) — single pass through the array after O(n) accumulate call.
 * Space Complexity: O(1) — only a constant number of variables used.
 *
 * Runtime: 0 ms
 * Memory: 22.5 MB
 */

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];
            if ((total - 2 * left) % 2 == 0) count++;
        }
        return count;
    }
};
