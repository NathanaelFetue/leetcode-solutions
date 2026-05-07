/*
 * Problem #3583 - Count Special Triplets (Medium)
 * https://leetcode.com/problems/count-special-triplets/
 *
 * Approach: Hash Map with Prefix Counting
 * For each element v treated as the middle element of a triplet, count elements
 * equal to 2*v that appear strictly before it (left count) and strictly after it
 * (right count), then multiply left * right to get valid triplets centered at v.
 * A running prefix map tracks elements seen so far, while a precomputed total
 * frequency map enables O(1) right-count lookups (total - prefix count).
 *
 * Time Complexity : O(n) - single precomputation pass and one linear scan,
 *                   each hash map operation is O(1) amortized.
 * Space Complexity: O(n) - two hash maps storing at most n distinct values.
 *
 * Runtime : 775 ms
 * Memory  : 400 MB
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        numCnt.reserve(nums.size() * 2);
        numPartialCnt.reserve(nums.size() * 2);

        for (int v : nums) {
            numCnt[v]++;
        }

        int ans = 0;
        for (int v : nums) {
            int target = v * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[v]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return ans;
    }
};
