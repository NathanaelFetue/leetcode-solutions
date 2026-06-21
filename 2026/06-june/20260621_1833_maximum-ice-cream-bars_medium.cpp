/*
 * Problem #1833 - Maximum Ice Cream Bars (Medium)
 * URL: https://leetcode.com/problems/maximum-ice-cream-bars/
 *
 * Approach: Counting Sort / Frequency Array Greedy
 * Build a frequency array indexed by cost value, then greedily iterate from
 * the cheapest cost upward, buying as many bars as possible at each price
 * level given the remaining coins. This ensures we maximize the count.
 *
 * Time Complexity: O(n + m) where n is the number of bars and m is the
 * maximum cost value. Building the frequency array is O(n) and iterating
 * over it is O(m).
 *
 * Space Complexity: O(m) where m is the maximum cost value, used for the
 * frequency array.
 *
 * Runtime: 0 ms
 * Memory: 84.5 MB
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
