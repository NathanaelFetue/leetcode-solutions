/*
 * Problem 1722: Minimize Hamming Distance After Swap Operations (Medium)
 * https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
 *
 * Approach: Union-Find (Disjoint Set Union)
 * Group indices into connected components using Union-Find based on allowedSwaps.
 * For each component, count source value frequencies, then greedily match target values;
 * any target value with no remaining source match contributes to the Hamming distance.
 *
 * Time Complexity: O(n * alpha(n) + n) where alpha is the inverse Ackermann function
 * from Union-Find operations; effectively O(n) for grouping and frequency matching.
 *
 * Space Complexity: O(n) for the parent array, groups map, and frequency maps.
 *
 * Runtime: 155 ms
 * Memory: 153 MB
 */

class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        for (auto& swap : allowedSwaps) unite(swap[0], swap[1]);
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);
        
        int dist = 0;
        for (auto& [root, indices] : groups) {
            unordered_map<int, int> freq;
            for (int i : indices) freq[source[i]]++;
            for (int i : indices) {
                if (freq[target[i]] > 0) freq[target[i]]--;
                else dist++;
            }
        }
        return dist;
    }
};
