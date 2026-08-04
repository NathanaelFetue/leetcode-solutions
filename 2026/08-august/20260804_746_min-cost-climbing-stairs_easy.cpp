/*
 * Problem #746 - Min Cost Climbing Stairs (Easy)
 * https://leetcode.com/problems/min-cost-climbing-stairs/
 *
 * Approach: Bottom-Up Dynamic Programming with Constant Space
 * Instead of using a DP array, we track only the two most recent step costs (prev1, prev2).
 * At each step i, the minimum cost is the lesser of the two previous costs plus the current step's cost.
 * After iterating, the answer is the minimum of the last two values since we can start from step 0 or 1.
 *
 * Time Complexity : O(n) - single pass through the cost array of size n.
 * Space Complexity : O(1) - only two integer variables used regardless of input size.
 *
 * Runtime : 0 ms
 * Memory  : 17.6 MB
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0] , prev2 = cost[1];
        for(int i=2 ; i<cost.size(); i++){
            int current = min(prev1 , prev2) + cost[i];
            prev1 = prev2;
            prev2 = current;
        }

        return min(prev1 , prev2);
    }
};
