/*
 * Problem #200: Number of Islands
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/number-of-islands/
 *
 * Approach: Depth-First Search (DFS) with in-place grid modification.
 * For each unvisited land cell ('1'), increment the island count and trigger a DFS
 * that marks all connected land cells as visited by overwriting them with '0',
 * effectively sinking the entire island to avoid double-counting.
 *
 * Time Complexity: O(M * N) where M is the number of rows and N is the number of
 * columns; each cell is visited at most once across all DFS calls.
 *
 * Space Complexity: O(M * N) in the worst case due to the recursive call stack
 * when the grid is filled entirely with land and DFS recurses deeply.
 *
 * Runtime: 25 ms | Memory: 16.3 MB
 */

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n  || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }

            }
        }

        return islands;
    }
};
