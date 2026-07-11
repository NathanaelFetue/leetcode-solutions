/*
 * 2685. Count the Number of Complete Components
 * Difficulty: Medium
 * https://leetcode.com/problems/count-the-number-of-complete-components/
 *
 * Approach: Adjacency List Fingerprinting
 * For each vertex, build a sorted adjacency list that includes a self-loop (the vertex itself).
 * This sorted list acts as a unique fingerprint: in a complete component of size k, every vertex
 * must have exactly k neighbors (including itself), and all k vertices must share the same fingerprint.
 * Count each unique fingerprint's frequency; if the frequency equals the component size (number of commas),
 * that component is complete.
 *
 * Time Complexity: O(n log n + E log E) — sorting adjacency lists per vertex dominates,
 * where E is the number of edges.
 * Space Complexity: O(n + E) — for the adjacency lists and the frequency map.
 *
 * Runtime: 56 ms
 * Memory: 143.2 MB
 */

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // adjacency lists for each vertex
        vector<vector<int>> graph(n);
        // map to store frequency of each unique adjacency list
        unordered_map<string, int> componentFreq;

        // initialize adjacency lists with self-loops
        for (int vertex = 0; vertex < n; vertex++) {
            graph[vertex].push_back(vertex);
        }

        // build adjacency lists from edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // count frequency of each unique adjacency pattern
        for (int vertex = 0; vertex < n; vertex++) {
            vector<int> neighbors = graph[vertex];
            sort(neighbors.begin(), neighbors.end());

            // convert vector to string for hashing
            string key;
            for (int num : neighbors) {
                key += to_string(num) + ",";
            }
            componentFreq[key]++;
        }

        // count complete components where size equals frequency
        int completeCount = 0;
        for (const auto& entry : componentFreq) {
            // count commas to get original vector size
            int size = count(entry.first.begin(), entry.first.end(), ',');
            if (size == entry.second) {
                completeCount++;
            }
        }

        return completeCount;
    }
};
