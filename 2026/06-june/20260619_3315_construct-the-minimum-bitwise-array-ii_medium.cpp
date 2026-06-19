/*
 * Problem #3315 - Construct the Minimum Bitwise Array II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
 *
 * Approach/Algorithm:
 * For each prime number in nums, we need to find the minimum x such that (x | (x+1)) == nums[i].
 * The key insight is that (x | (x+1)) sets the lowest 0-bit of x to 1, so we find the position
 * of the lowest 0-bit in nums[i] (by scanning past trailing 1-bits), then clear the bit just
 * below it to produce the minimum valid x. If nums[i] == 2 (binary 10), no valid x exists.
 *
 * Time Complexity: O(n * log(max(nums)))
 *   - For each of the n elements, we scan at most log2(max(nums)) bits to find the lowest 0-bit.
 *
 * Space Complexity: O(n)
 *   - Output result array of size n; no additional auxiliary structures used.
 *
 * Runtime: 0 ms | Memory: 28.3 MB
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i =0; i<n; i++) {
            if(nums[i]==2) {
                continue;
            }
            int q = 0;
            while ((nums[i] >> q) & 1) q++;
            res[i] = nums[i] ^ (1 << (q - 1));
        }
        return res;
    }
};
