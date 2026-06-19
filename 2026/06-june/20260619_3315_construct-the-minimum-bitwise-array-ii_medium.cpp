/*
 * Problem 3315: Construct the Minimum Bitwise Array II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
 *
 * Approach: For each number in nums, we need to find the minimum x such that x | (x+1) == nums[i].
 * The key insight is that x | (x+1) flips the lowest 0-bit of x to 1, so we find the position of
 * the lowest 0-bit in nums[i] (by scanning past trailing 1s) and clear the bit just below it.
 * Special case: nums[i] == 2 has no valid answer, so it remains -1.
 *
 * Algorithm: Bit manipulation - find lowest 0-bit position q via trailing 1s scan,
 * then compute result as nums[i] XOR (1 << (q-1)) to clear the bit below the lowest 0-bit.
 *
 * Time Complexity: O(n * log(max_val)) - for each of n elements, we scan up to log2(max_val) bits.
 * Space Complexity: O(n) - for the result array of size n.
 *
 * Runtime: 0 ms | Memory: 28.1 MB
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
