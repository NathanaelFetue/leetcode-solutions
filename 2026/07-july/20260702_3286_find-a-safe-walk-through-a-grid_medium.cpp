/*
 * Problem #3286: Find a Safe Walk Through a Grid (Medium)
 * https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
 *
 * Approach: Dijkstra's shortest path algorithm on a 2D grid.
 * Each cell's edge weight equals the cell's value (1 if unsafe, 0 if safe).
 * We find the minimum total health cost to reach the bottom-right corner,
 * then check if that cost is strictly less than the given health value.
 *
 * Algorithm:
 * - Use a min-heap priority queue storing (accumulated_cost, row, col).
 * - Greedily expand the least-cost cell first, tracking visited cells via a dis array.
 * - If the minimum cost path to (m-1, n-1) is less than health, a safe walk exists.
 *
 * Time Complexity: O(m * n * log(m * n)) - each cell processed once with heap operations.
 * Space Complexity: O(m * n) - for the distance array and priority queue.
 *
 * Runtime: 34 ms | Memory: 32.2 MB
 */

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            if (dis[cx][cy] >= 0) {
                continue;
            }
            dis[cx][cy] = val;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                    dis[nx][ny] >= 0) {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};
