/*
 * Problem #2141: Maximum Running Time of N Computers
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 *
 * Approach: Binary search on the answer (running time t).
 * For a candidate time t, check feasibility by summing min(battery, t) across all batteries;
 * if the total available charge >= n * t, then t minutes is achievable.
 * The upper bound for binary search is total_charge / n, since we cannot exceed average.
 *
 * Time Complexity: O(m log(total/n)) where m = number of batteries and total = sum of all battery values.
 *   - Sorting is O(m log m), binary search runs O(log(total/n)) iterations, each O(m).
 * Space Complexity: O(1) extra space (sorting is in-place, only scalar variables used).
 *
 * Runtime : 83 ms
 * Memory  : 63.2 MB
 */

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (int b : batteries) total += b;
        
        sort(batteries.rbegin(), batteries.rend());
        
        // binary search sur le temps t
        long long lo = 0, hi = total / n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            // peut-on faire tourner n ordinateurs pendant mid minutes ?
            long long available = 0;
            for (int b : batteries)
                available += min((long long)b, mid);
            if (available >= (long long)n * mid) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
