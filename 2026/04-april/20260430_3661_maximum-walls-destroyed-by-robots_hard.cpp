/*
 * Problem #3661 - Maximum Walls Destroyed by Robots
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/maximum-walls-destroyed-by-robots/
 *
 * Approach: Sort robots by position, then apply dynamic programming where each state
 * tracks whether the current robot fires left (dp[0]) or right (dp[1]). For each robot,
 * compute its reachable wall ranges (clamped by neighbors) and handle overlaps between
 * adjacent robots when robot i-1 fires right and robot i fires left using binary search
 * on the sorted walls array to count walls in any range in O(log W) time.
 *
 * Time Complexity: O(N log N + W log W + N log W) - sorting robots and walls takes
 * O(N log N + W log W), and each DP step performs O(log W) binary searches over N steps.
 *
 * Space Complexity: O(N + W) - for sorted index array, reordered robot/distance arrays,
 * and the sorted walls array; DP uses O(1) rolling state.
 *
 * Runtime: 282 ms | Memory: 205.3 MB
 */

class Solution {
public:
    int countWalls(vector<int>& walls, int l, int r) {
        if (l > r) return 0;
        return (int)(upper_bound(walls.begin(), walls.end(), r) - 
                     lower_bound(walls.begin(), walls.end(), l));
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return robots[a] < robots[b]; });
        
        vector<int> r(n), d(n);
        for (int i = 0; i < n; i++) { r[i] = robots[idx[i]]; d[i] = distance[idx[i]]; }
        sort(walls.begin(), walls.end());

        // portée gauche de i : toujours bloquée par i-1
        // portée droite de i : toujours bloquée par i+1
        auto leftRange = [&](int i) -> pair<int,int> {
            int l = r[i] - d[i];
            if (i > 0) l = max(l, r[i-1] + 1);
            return {l, r[i]};
        };
        auto rightRange = [&](int i) -> pair<int,int> {
            int right = r[i] + d[i];
            if (i < n-1) right = min(right, r[i+1] - 1);
            return {r[i], right};
        };

        auto [l0, r0] = leftRange(0);
        auto [rl0, rr0] = rightRange(0);
        vector<long long> dp = {countWalls(walls, l0, r0), countWalls(walls, rl0, rr0)};

        for (int i = 1; i < n; i++) {
            vector<long long> ndp(2, 0);

            auto [lL, lR] = leftRange(i);
            auto [rL, rR] = rightRange(i);

            int wLeft = countWalls(walls, lL, lR);
            int wRight = countWalls(walls, rL, rR);

            // overlap quand i-1 tire droite et i tire gauche
            auto [prevRL, prevRR] = rightRange(i-1);
            int overlapL = max(lL, prevRL);
            int overlapR = min(lR, prevRR);
            int overlap = countWalls(walls, overlapL, overlapR);

            ndp[0] = max(dp[0] + wLeft,           // i-1 tire gauche, pas d'overlap
                         dp[1] + wLeft - overlap); // i-1 tire droite, overlap

            ndp[1] = max(dp[0], dp[1]) + wRight;  // pas d'overlap possible

            dp = ndp;
        }

        return (int)max(dp[0], dp[1]);
    }
};
