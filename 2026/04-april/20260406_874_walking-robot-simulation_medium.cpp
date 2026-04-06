/*
 * 874. Walking Robot Simulation - Medium
 * https://leetcode.com/problems/walking-robot-simulation/
 *
 * Approach: Simulate robot movement using directional arrays for North, East, South, West.
 * Store all obstacles in a hash set for O(1) lookup. For each move command, step one unit
 * at a time, breaking early if the next cell contains an obstacle, and tracking the maximum
 * Euclidean distance squared from the origin.
 *
 * Time Complexity: O(N + M*K) where N = number of obstacles, M = number of commands,
 * and K = max steps per command (up to 9). Obstacle lookup is O(log N) with std::set.
 * Space Complexity: O(N) for storing all obstacle coordinates in the set.
 *
 * Runtime: 27 ms
 * Memory: 37.9 MB
 */

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;
        
        set<pair<int,int>> obs;
        for (auto& o : obstacles)
            obs.insert({o[0], o[1]});
        
        int x = 0, y = 0, maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) dir = (dir + 1) % 4;
            else if (cmd == -2) dir = (dir + 3) % 4;
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obs.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};
