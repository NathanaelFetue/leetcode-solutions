/*
 * Problem 485: Max Consecutive Ones (Easy)
 * https://leetcode.com/problems/max-consecutive-ones/
 *
 * Approach: Single-pass linear scan with a running counter.
 * For each element, if it is 1 the counter is incremented; otherwise it resets to 0.
 * After each step the global best is updated with the maximum of itself and the counter.
 *
 * Time Complexity : O(n) — each element is visited exactly once.
 * Space Complexity: O(1) — only two integer variables are maintained regardless of input size.
 *
 * Runtime : 0 ms
 * Memory  : 50.2 MB
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cpt = 0, best = 0;
        for (int x : nums) {
            cpt = (x == 1) ? cpt + 1 : 0;
            best = max(best, cpt);
        }
        return best;
    }
};
