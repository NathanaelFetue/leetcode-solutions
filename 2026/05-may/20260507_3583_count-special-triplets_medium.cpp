/*
 * Problem #3583 - Count Special Triplets (Medium)
 * https://leetcode.com/problems/count-special-triplets/
 *
 * Approach: Two-pass hash map with sliding window technique.
 * For each middle element nums[j], we count valid triplets where nums[i] == 2*nums[j] on the left
 * and nums[k] == 2*nums[j] on the right, multiplying the two counts for each j.
 * We maintain a `left` map of seen elements and a `right` map of remaining elements,
 * updating both as we iterate through each index j.
 *
 * Time Complexity : O(n) - single pass over the array with O(1) average hash map operations.
 * Space Complexity: O(n) - two hash maps storing at most n distinct elements combined.
 *
 * Runtime : 549 ms
 * Memory  : 368 MB
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // compter les occurrences à gauche
        unordered_map<int, long long> left;
        // compter les occurrences à droite
        unordered_map<int, long long> right;
        
        // initialiser right avec tous les éléments
        for (int x : nums) right[x]++;
        
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            right[nums[j]]--;  // retirer j de right
            
            long long target = (long long)nums[j] * 2;
            long long leftCount  = left.count(target)  ? left[target]  : 0;
            long long rightCount = right.count(target) ? right[target] : 0;
            
            ans = (ans + leftCount * rightCount) % MOD;
            
            left[nums[j]]++;  // ajouter j à left
        }
        return ans;
    }
};
