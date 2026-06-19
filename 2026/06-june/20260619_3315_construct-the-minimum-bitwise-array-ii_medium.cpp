/*
 * Problem 3315: Construct the Minimum Bitwise Array II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
 *
 * Approach/Algorithm:
 * For each prime number in nums, we need to find the smallest x such that (x | (x+1)) == nums[i].
 * The key insight is that (x | (x+1)) sets the lowest 0-bit of x to 1, so to reverse this,
 * we find the position q of the lowest 0-bit in nums[i] and clear the bit just below it (q-1).
 * If nums[i] == 2 (binary 10), no valid x exists, so we return -1 for that entry.
 *
 * Time Complexity: O(n * log(max_val)) - for each of the n elements we scan at most log2(nums[i]) bits
 * to find the lowest zero bit.
 *
 * Space Complexity: O(n) - for the result array of size n.
 *
 * Runtime: 3 ms
 * Memory: 28.2 MB
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i =0; i<n; i++) {
            if(nums[i]!=2) {
                int q = 0;
                while ((nums[i] >> q) & 1) q++;
                res[i] = nums[i] ^ (1 << (q - 1));
            }
        }
        return res;
    }
};
