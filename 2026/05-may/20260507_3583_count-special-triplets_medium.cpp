/*
 * Problem #3583 - Count Special Triplets (Medium)
 * https://leetcode.com/problems/count-special-triplets/
 *
 * Approach: Hash Map Prefix/Suffix Count
 * For each middle element nums[j], a valid triplet requires nums[i] == nums[j]*2 and nums[k] == nums[j]*2,
 * meaning both the left and right neighbors must equal twice the middle value.
 * We maintain a left frequency map (elements before j) and a right frequency map (elements after j),
 * then for each j, multiply left[2*nums[j]] * right[2*nums[j]] to count valid triplets.
 *
 * Time Complexity: O(n) - single pass through the array with O(1) average hash map operations.
 * Space Complexity: O(n) - two hash maps each storing at most n distinct values.
 *
 * Runtime : 933 ms
 * Memory  : 520.5 MB
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // forcer une meilleure distribution pour éviter les collisions
        unordered_map<int, long long> left, right;
        left.reserve(n);  right.reserve(n);
        left.max_load_factor(0.25);
        right.max_load_factor(0.25);
        
        for (int x : nums) right[x]++;
        
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            right[nums[j]]--;
            long long target = (long long)nums[j] * 2;
            ans = (ans + left[target] * right[target]) % MOD;
            left[nums[j]]++;
        }
        return (int)ans;
    }
};
