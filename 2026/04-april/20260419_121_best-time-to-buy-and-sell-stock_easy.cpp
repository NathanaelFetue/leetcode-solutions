/*
 * Problem #121 - Best Time to Buy and Sell Stock (Easy)
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Approach: Single-pass greedy scan.
 * Iterate through prices while tracking the minimum price seen so far.
 * At each step, either update the minimum price or compute profit against it and track the best.
 *
 * Time Complexity: O(n) - single pass through the prices array of size n.
 * Space Complexity: O(1) - only two integer variables used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 97.2 MB
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
