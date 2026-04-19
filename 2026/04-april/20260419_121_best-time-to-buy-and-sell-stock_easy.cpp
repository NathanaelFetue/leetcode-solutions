/*
 * Problem #121 - Best Time to Buy and Sell Stock (Easy)
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Approach: Single-pass greedy scan.
 * Iterate through prices tracking the minimum price seen so far.
 * At each step, compute the profit if selling at the current price and update the best profit found.
 * If the current price is lower than the tracked minimum, update the minimum instead.
 *
 * Time Complexity: O(n) - single linear scan through the prices array of size n.
 * Space Complexity: O(1) - only two integer variables (best, minPrice) are used regardless of input size.
 *
 * Runtime : 4 ms
 * Memory  : 97.3 MB
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best = 0, minPrice = prices[0];
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] > minPrice)
                best = max(best, prices[i] - minPrice);
            else
                minPrice = prices[i];
        }
        return best;
    }
};
