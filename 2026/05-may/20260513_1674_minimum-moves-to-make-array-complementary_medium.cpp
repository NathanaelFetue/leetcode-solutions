/*
 * Problem #1674 - Minimum Moves to Make Array Complementary
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
 *
 * Approach: Difference Array (Line Sweep)
 * For each symmetric pair (a, b) where a <= b, the cost to reach any target sum t
 * starts at 2, drops to 1 in [a+1, 2*limit], drops to 0 at exactly t=a+b, then rises
 * back to 1, and rises to 2 again in [b+limit+1, 2*limit]. A difference array encodes
 * these cost deltas across all valid target sums [2, 2*limit], and a single prefix scan
 * finds the minimum total moves over all pairs.
 *
 * Time Complexity: O(n + limit) - O(n/2) to build the diff array, O(limit) to scan it.
 * Space Complexity: O(limit) - for the difference array of size 2*limit + 2.
 *
 * Runtime: 12 ms
 * Memory: 93.5 MB
 */

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        // diff array sur [2, 2*limit]
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            // Base : tout le monde coûte 2> on va soustraire
            // [a+1, 2*limit] : coûte 1 au lieu de 2 -> diff -1
            diff[a + 1]         -= 1;
            diff[2 * limit + 1] += 1;

            // [a+b, a+b] : coûte 0 au lieu de 1 -> diff -1
            diff[a + b]         -= 1;
            diff[a + b + 1]     += 1;

            // [b+limit+1, 2*limit] : coûte 2 au lieu de 1 -> diff +1
            diff[b + limit + 1] += 1;
            diff[2 * limit + 1] -= 1;
        }

        // Chercher le minimum en construisant le préfixe
        int ans = INT_MAX;
        int base = n; // n/2 paires * 2 moves chacune
        int cur = 0;
        for (int t = 2; t <= 2 * limit; t++) {
            cur += diff[t];
            ans = min(ans, base + cur);
        }
        return ans;
    }
};
