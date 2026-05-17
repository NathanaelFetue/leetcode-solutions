/*
 * Problem #1306 - Jump Game III (Medium)
 * LeetCode: https://leetcode.com/problems/jump-game-iii/
 *
 * Approach: Breadth-First Search (BFS)
 * Starting from the given index, we use BFS to explore all reachable indices by jumping
 * either forward (i + arr[i]) or backward (i - arr[i]) from each position. We mark indices
 * as visited to avoid revisiting them, and return true immediately if we land on an index
 * where arr[i] == 0, otherwise return false if all reachable nodes are exhausted.
 *
 * Time Complexity : O(n) - each index is visited at most once across the entire BFS traversal.
 * Space Complexity: O(n) - for the visited array and the BFS queue, both of size at most n.
 *
 * Runtime : 0 ms
 * Memory  : 35.4 MB
 */

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int i = q.front(); q.pop();
            
            if (arr[i] == 0) return true;
            
            for (int next : {i + arr[i], i - arr[i]}) {
                if (next >= 0 && next < n && !visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
    }
};
