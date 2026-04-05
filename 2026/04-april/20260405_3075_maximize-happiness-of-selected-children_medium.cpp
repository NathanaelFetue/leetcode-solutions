/*
 * Problem 3075: Maximize Happiness of Selected Children (Medium)
 * https://leetcode.com/problems/maximize-happiness-of-selected-children/
 *
 * Approach: Greedy with Sorted Descending Order
 * Sort the happiness array in descending order to greedily pick the highest values first.
 * For each selection turn, reduce the child's happiness by the number of turns already taken (since each prior selection decreases remaining values by 1), and accumulate only non-negative contributions using max(0, happiness[i] - turn).
 *
 * Time Complexity: O(n log n) — dominated by sorting the happiness array of size n.
 * Space Complexity: O(1) — sorting is done in-place and only a constant number of extra variables are used.
 *
 * Runtime: 155 ms
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
