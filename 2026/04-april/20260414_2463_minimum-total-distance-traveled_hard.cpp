/*
 * Problem #2463 - Minimum Total Distance Traveled (Hard)
 * LeetCode: https://leetcode.com/problems/minimum-total-distance-traveled/
 *
 * Approach: Dynamic Programming with sorting.
 * Both robots and factories are sorted by position so that optimal assignments are always contiguous.
 * dp[i][j] represents the minimum total distance for robots[i..n-1] to be repaired using factories[j..m-1].
 * For each factory j and robot i, we try assigning k consecutive robots (up to factory capacity) to factory j,
 * accumulating distances and taking the minimum over all valid k.
 *
 * Time Complexity: O(n * m * C) where n = number of robots, m = number of factories,
 * and C = max factory capacity. Each state considers up to C assignments.
 *
 * Space Complexity: O(n * m) for the 2D DP table.
 *
 * Runtime: 27 ms | Memory: 13.3 MB
 */

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][m] = 1e18;

        for (int j = m - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                dp[i][j] = dp[i][j + 1];

                long long dist = 0;
                for (int k = 1; k <= factory[j][1] && i + k - 1 < n; k++) {
                    dist += abs(robot[i + k - 1] - factory[j][0]);
                    dp[i][j] = min(dp[i][j], dist + dp[i + k][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
