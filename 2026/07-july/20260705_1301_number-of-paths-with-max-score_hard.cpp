/*
 * 1301. Number of Paths with Max Score
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/number-of-paths-with-max-score/
 *
 * Approach: Bottom-up dynamic programming starting from the bottom-right cell ('E') and
 * working toward the top-left cell ('S'). For each cell, we look at three possible
 * next steps (down, right, diagonal) and greedily track both the maximum reachable
 * score and the number of paths achieving that maximum score.
 *
 * Time Complexity: O(n^2) - each cell in the n x n board is visited exactly once.
 * Space Complexity: O(n^2) - two n x n tables store the max score and path count
 * for every cell.
 *
 * Runtime: 30 ms
 * Memory: 17.9 MB
 */

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();
        
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> paths(n, vector<int>(n, 0));
        
        score[n-1][n-1] = 0;
        paths[n-1][n-1] = 1;
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                if (i == n-1 && j == n-1) continue;
                
                vector<pair<int,int>> prev = {{i+1,j}, {i,j+1}, {i+1,j+1}};
                for (auto [pi, pj] : prev) {
                    if (pi >= n || pj >= n) continue;
                    if (score[pi][pj] == -1) continue; 
                    
                    if (score[pi][pj] > score[i][j]) {
                        score[i][j] = score[pi][pj];
                        paths[i][j] = paths[pi][pj];
                    } else if (score[pi][pj] == score[i][j]) {
                        paths[i][j] = (paths[i][j] + paths[pi][pj]) % MOD;
                    }
                }
                
                if (score[i][j] != -1 && board[i][j] != 'E')
                    score[i][j] += board[i][j] - '0';
            }
        }
        
        if (score[0][0] == -1) return {0, 0};
        return {score[0][0], paths[0][0]};
    }
};
