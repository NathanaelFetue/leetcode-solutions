/*
 * Problem #1345 - Jump Game IV (Hard)
 * URL: https://leetcode.com/problems/jump-game-iv/
 *
 * Approach: BFS (Breadth-First Search) on an implicit graph.
 * Each index is a node; edges connect index i to i-1, i+1, and all indices sharing
 * the same value as arr[i]. BFS guarantees the shortest path (minimum jumps) is found
 * first. To avoid redundant processing, the adjacency list for each value group is
 * cleared after its indices are visited, preventing re-traversal of already-queued nodes.
 *
 * Time Complexity: O(n) - each index is visited at most once; clearing the graph
 * ensures value-group edges are traversed only once in total across all BFS levels.
 *
 * Space Complexity: O(n) - for the hash map storing value-to-indices groupings,
 * the visited array, and the BFS queue, all of which scale linearly with input size.
 *
 * Runtime : 73 ms
 * Memory  : 74.8 MB
 */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        
        // Grouper les indices par valeur
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
            graph[arr[i]].push_back(i);
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        
        while (!q.empty()) {
            steps++;
            int size = q.size();
            
            while (size--) {
                int i = q.front(); q.pop();
                
                // Sauts par valeur égale
                for (int j : graph[arr[i]]) {
                    if (!visited[j]) {
                        if (j == n - 1) return steps;
                        visited[j] = true;
                        q.push(j);
                    }
                }
                graph[arr[i]].clear();
                
                // Sauts i+1 et i-1
                for (int next : {i + 1, i - 1}) {
                    if (next >= 0 && next < n && !visited[next]) {
                        if (next == n - 1) return steps;
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
