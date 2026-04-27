/*
 * Problem #1391: Check if There is a Valid Path in a Grid (Medium)
 * URL: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 *
 * Approach: BFS traversal from cell (0,0) to cell (m-1,n-1) using a street-type direction map.
 * Each street type (1-6) defines exactly two connection directions. For each neighbor
 * reached from the current cell, we verify the neighbor's street also connects back,
 * ensuring bidirectional compatibility before enqueuing it.
 *
 * Time Complexity: O(m * n) - each cell is visited at most once, and direction checks
 * are O(1) since each street type has at most 2 directions.
 *
 * Space Complexity: O(m * n) - for the visited matrix and BFS queue in the worst case.
 *
 * Runtime: 20 ms | Memory: 57.3 MB
 */

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // pour chaque type, quelles directions sont accessibles ?
        // {di, dj} : 0=droite, 1=bas, 2=gauche, 3=haut
        vector<vector<pair<int,int>>> dirs = {
            {},                      // type 0 (inexistant)
            {{0,1},{0,-1}},         // type 1 : gauche-droite
            {{1,0},{-1,0}},         // type 2 : haut-bas
            {{1,0},{0,-1}},         // type 3 : gauche-bas
            {{1,0},{0,1}},          // type 4 : droite-bas
            {{-1,0},{0,-1}},        // type 5 : gauche-haut
            {{-1,0},{0,1}}          // type 6 : droite-haut
        };

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == m-1 && j == n-1) return true;
            for (auto [di, dj] : dirs[grid[i][j]]) {
                int ni = i+di, nj = j+dj;
                if (ni<0||ni>=m||nj<0||nj>=n||visited[ni][nj]) continue;
                // vérifier que le voisin se connecte en retour
                bool connected = false;
                for (auto [rdi, rdj] : dirs[grid[ni][nj]])
                    if (ni+rdi==i && nj+rdj==j) { connected=true; break; }
                if (connected) { visited[ni][nj]=true; q.push({ni,nj}); }
            }
        }
        return false;
    }
};
