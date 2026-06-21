/*
 * Problem #1833 - Maximum Ice Cream Bars (Medium)
 * LeetCode URL: https://leetcode.com/problems/maximum-ice-cream-bars/
 *
 * Approach: Greedy with Counting Sort (Frequency Array)
 * Build a frequency array indexed by cost value, then greedily purchase as many
 * bars as possible starting from the cheapest price, buying the maximum affordable
 * quantity at each price level before moving to the next.
 *
 * Time Complexity: O(n + m) where n is the number of bars and m is the maximum
 * cost value. One pass to build frequency array, one pass over cost range.
 *
 * Space Complexity: O(m) for the frequency array of size max_cost + 1.
 *
 * Runtime: 4 ms
 * Memory: 84.4 MB
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int big = *max_element(costs.begin(), costs.end());
        vector<int> freq(big + 1, 0);

        for (int c : costs) freq[c]++;

        int nb = 0;
        for (int i = 1; i < freq.size(); i++) {
            if (coins <= 0 || freq[i] == 0) continue;

            int canBuy = min(freq[i], coins / i);
            nb += canBuy;
            coins -= canBuy * i;
        }
        return nb;
    }
};
