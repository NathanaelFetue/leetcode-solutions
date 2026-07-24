/*
 * Problem #3514: Number of Unique XOR Triplets II (Medium)
 * https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
 *
 * Approach: Two-pass XOR enumeration with bitset-style marking.
 * First, compute all unique XOR values of pairs (i <= j) and store them in a boolean array s[].
 * Then, for each unique pair XOR, XOR it with every element in nums, marking results in t[].
 * Finally, count all distinct values in t[] which represent unique triplet XOR results.
 *
 * Time Complexity: O(n^2 + P*n) where P is the number of unique pair XORs (at most u = next
 * power of 2 above max element). In the worst case this is O(n^2) dominated by pair generation.
 *
 * Space Complexity: O(u) where u is the smallest power of 2 greater than max(nums), used for
 * the two marking arrays s[] and t[].
 *
 * Runtime: 391 ms | Memory: 48.5 MB
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for (int v : nums) {
            m = max(m, v);
        }
        int u = 1;
        while (u <= m) {
            u <<= 1;
        }
        vector<int> s(u);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i] ^ nums[j]] = 1;
            }
        }
        vector<int> t(u);
        for (int x = 0; x < u; x++) {
            if (!s[x]) {
                continue;
            }
            for (int v : nums) {
                t[x ^ v] = 1;
            }
        }
        int ans = 0;
        for (int x = 0; x < u; x++) {
            if (t[x]) {
                ans++;
            }
        }
        return ans;
    }
};
