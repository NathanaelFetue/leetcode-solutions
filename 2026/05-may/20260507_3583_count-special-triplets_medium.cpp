/*
 * Problem #3583 - Count Special Triplets (Medium)
 * https://leetcode.com/problems/count-special-triplets/
 *
 * Approach: Single-pass hash map with prefix and suffix frequency counts.
 * For each middle element nums[j], a valid triplet requires nums[i] == nums[j]/2
 * and nums[k] == nums[j]*2, so we count left[2*nums[j]] * right[2*nums[j]] contributions.
 * We maintain a 'left' map of elements seen before j and a 'right' map of elements
 * after j, updating both maps as we iterate through the array.
 *
 * Time Complexity : O(n) — single pass through the array with O(1) average hash map ops.
 * Space Complexity: O(n) — two hash maps storing at most n distinct element frequencies.
 *
 * Runtime : 994 ms
 * Memory  : 465.5 MB
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
