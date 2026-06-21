/*
 * 1833. Maximum Ice Cream Bars - Medium
 * https://leetcode.com/problems/maximum-ice-cream-bars/
 *
 * Approach: Greedy with Sorting
 * Sort the costs array in ascending order so the cheapest ice cream bars come first.
 * Iterate through the sorted costs, greedily purchasing each bar if coins remain sufficient, stopping as soon as we can no longer afford the next bar.
 * This greedy strategy guarantees the maximum number of bars since spending less per bar leaves more coins for additional purchases.
 *
 * Time Complexity: O(n log n) - dominated by sorting the costs array of size n.
 * Space Complexity: O(1) - sorting is done in-place and only a constant number of extra variables are used (excluding input).
 *
 * Runtime: 38 ms
 * Memory: 80.2 MB
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;

        for (int cost : costs) {
            if (coins < cost) break;
            coins -= cost;
            count++;
        }
        return count;
    }
};
