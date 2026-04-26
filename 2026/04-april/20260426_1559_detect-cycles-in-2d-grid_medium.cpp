/*
 * Problem #1559 - Detect Cycles in 2D Grid (Medium)
 * https://leetcode.com/problems/detect-cycles-in-2d-grid/
 *
 * Approach: Depth-First Search (DFS) with visited tracking.
 * For each unvisited cell, perform a DFS traversing only adjacent cells with the same character.
 * If we encounter an already-visited cell that is not the immediate parent, a cycle exists.
 *
 * Time Complexity: O(m * n) — each cell is visited at most once across all DFS calls.
 * Space Complexity: O(m * n) — for the visited matrix and implicit DFS call stack depth.
 *
 * Runtime: 24 ms
 * Memory: 66.9 MB
 */

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            if (nx == px && ny == py) continue; // parent
            if (visited[nx][ny]) return true;   // cycle !
            if (dfs(grid, nx, ny, x, y)) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j])
                    if (dfs(grid, i, j, -1, -1)) return true;
        return false;
    }
};
