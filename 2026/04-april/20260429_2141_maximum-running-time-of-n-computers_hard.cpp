/*
 * Problem #2141: Maximum Running Time of N Computers
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 *
 * Approach: Binary search on the answer (the running time T).
 * For a candidate time T, each battery can contribute at most min(battery, T) units.
 * If the total available power across all batteries is >= n * T, then T is achievable.
 * Binary search finds the maximum valid T in the range [0, total / n].
 *
 * Time Complexity: O(m * log(total / n)), where m is the number of batteries and
 * total is the sum of all battery capacities. Each binary search step is O(m).
 *
 * Space Complexity: O(1) extra space beyond input storage.
 *
 * Runtime: 21 ms
 * Memory: 59.8 MB
 */

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;
        
        long long lo = 0, hi = total / n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long available = 0;
            for (int b : batteries)
                available += min((long long)b, mid);
            if (available >= (long long)n * mid) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
