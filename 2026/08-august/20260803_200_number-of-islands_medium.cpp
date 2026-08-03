/*
 * Problem #200 - Number of Islands
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/number-of-islands/
 *
 * Approach: Depth-First Search (DFS) with in-place grid modification.
 * Iterate over every cell in the grid; when a '1' (land) is found, increment the island counter
 * and trigger a DFS that flood-fills all connected land cells to '0' to mark them as visited.
 * This ensures each island is counted exactly once without needing an extra visited array.
 *
 * Time Complexity: O(M x N) - every cell is visited at most once across all DFS calls,
 * where M is the number of rows and N is the number of columns.
 *
 * Space Complexity: O(M x N) - worst-case recursive call stack depth when the entire
 * grid is filled with land, leading to a DFS stack of size M x N.
 *
 * Runtime: 27 ms | Memory: 16.2 MB
 */

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size() , n = grid[0].size();
        if(i<0 || j<0 || i >=m || j >=n || grid[i][j] == '0'){
            return ;
        }
        grid[i][j] = '0';
        dfs(grid , i , j-1);
        dfs(grid , i-1 , j);
        dfs(grid , i,j+1);
        dfs(grid , i+1 , j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int islands = 0;

        for(int i= 0 ; i<m; i++) {
            for (int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid , i , j);
                }
            }
        }
        return islands;
    }
};
