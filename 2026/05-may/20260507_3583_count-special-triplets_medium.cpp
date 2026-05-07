/*
 * Problem #3583: Count Special Triplets (Medium)
 * URL: https://leetcode.com/problems/count-special-triplets/
 *
 * Approach: Prefix/Suffix Hash Map (One-Pass Middle Expansion)
 * For each index j treated as the middle element, count valid triplets where
 * nums[i] * 2 == nums[j] and nums[j] * 2 == nums[k] (i.e., nums[j] == 2*nums[i]
 * and nums[k] == 2*nums[j]). We maintain a left frequency map of elements before j
 * and a right frequency map of elements after j, multiplying left[2*nums[j]] by
 * right[2*nums[j]] to count valid (i, j, k) pairs in O(1) per element.
 *
 * Time Complexity: O(n) — single pass through the array with O(1) hash map ops.
 * Space Complexity: O(n) — two hash maps storing at most n distinct values.
 *
 * Runtime: 981 ms
 * Memory: 465.6 MB
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, long long> left, right;
        
        for (int x : nums) right[x]++;
        
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            right[nums[j]]--;
            long long target = (long long)nums[j] * 2;
            ans = (ans + left[target] * right[target]) % MOD;
            left[nums[j]]++;
        }
        return ans;
    }
};
