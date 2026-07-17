/*
 * Problem #3312: Sorted GCD Pair Queries (Hard)
 * URL: https://leetcode.com/problems/sorted-gcd-pair-queries/
 *
 * Approach: Inclusion-Exclusion with Prefix Sums on GCD Frequencies
 * 1. Count how many numbers in nums are divisible by each value i (frequency of multiples).
 * 2. Use inclusion-exclusion (Mobius-style sieve) to compute the exact count of pairs whose GCD equals exactly i, derived from C(cnt[i], 2) minus overcounted pairs with GCD as a multiple of i.
 * 3. Build a prefix sum over GCD pair counts, then answer each query with binary search (lower_bound) to find the GCD at a given sorted rank.
 *
 * Time Complexity: O(M log M + Q log M)
 *   - M = max(nums), sieve steps are O(M log M) (harmonic series)
 *   - Q queries each answered in O(log M) via binary search
 * Space Complexity: O(M)
 *   - cnt array of size M+1 for GCD pair counts and prefix sums
 *
 * Runtime: 34 ms | Memory: 122.9 MB
 */

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(m + 1);
        for (int num : nums) {
            cnt[num]++;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }
        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }
        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans;
        for (long long q : queries) {
            q++;
            int pos = lower_bound(cnt.begin(), cnt.end(), q) - cnt.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};
