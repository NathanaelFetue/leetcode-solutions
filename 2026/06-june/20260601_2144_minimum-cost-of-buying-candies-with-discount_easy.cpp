/*
 * Problem #2144: Minimum Cost of Buying Candies With Discount (Easy)
 * https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 *
 * Approach: Greedy with Sorting
 * Sort candies in descending order so the most expensive items are purchased first.
 * For every group of 3 candies (indices 0-1-2, 3-4-5, etc.), the third candy (every index where (i+1) % 3 == 0) is obtained for free.
 * Skip adding the cost of every third candy to maximize savings on the highest-priced items.
 *
 * Time Complexity: O(n log n) — dominated by sorting the cost array of size n.
 * Space Complexity: O(1) — sorting is done in-place and only a single integer accumulator is used.
 *
 * Runtime: 0 ms
 * Memory: 14.1 MB
 */

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end() , greater<int>());
        int total = 0;
        for(int i=0; i<cost.size();i++){
            if((i+1)%3 == 0) continue;
            total += cost[i];
        }
        return total;
    }
};
