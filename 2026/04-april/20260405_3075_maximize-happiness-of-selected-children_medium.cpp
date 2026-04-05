/*
 * Problem 3075: Maximize Happiness of Selected Children
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/maximize-happiness-of-selected-children/
 *
 * Approach: Greedy with Sorted Descending Order
 * Sort the happiness array in descending order to always pick the highest happiness values first.
 * For each selection turn (0-indexed), subtract the turn number from the happiness value since
 * each previously selected child reduces remaining happiness by 1. Use max(0, value) to avoid
 * negative contributions and accumulate the top k adjusted happiness values.
 *
 * Time Complexity: O(n log n) — dominated by sorting the happiness array of size n.
 * Space Complexity: O(1) — sorting is done in-place, only a few extra variables are used.
 *
 * Runtime: 157 ms
 * Memory: 107.7 MB
 */

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end() , greater<int>());
        long long tmp = 0;
        int turn =0;
        while (turn < k){
            tmp+= max(0, happiness[turn] - turn);
            turn++;
        }
        return tmp;
    }
};
