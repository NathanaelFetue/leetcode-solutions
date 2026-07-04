/*
 * Problem #2492 - Minimum Score of a Path Between Two Cities (Medium)
 * https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 *
 * Approach: Union-Find (Disjoint Set Union)
 * All nodes connected to node 1 (and transitively connected) form one component.
 * We union all edges first, then find the minimum weight edge whose endpoints belong to the same component as node 1.
 * This works because any edge in the connected component of node 1 is reachable and can contribute to the path score.
 *
 * Time Complexity: O(n + E * alpha(n)) where E is the number of roads and alpha is the inverse Ackermann function (near constant) for union-find operations.
 * Space Complexity: O(n) for the root/parent array used by the union-find structure.
 *
 * Runtime: 8 ms
 * Memory: 106.4 MB
 */

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> root(n + 1);
        iota(root.begin(), root.end(), 0);

        auto find = [&](this auto& self, int i) -> int {
            return root[i] == i ? i : root[i] = self(root[i]);
        };

        for (auto& r : roads)
            root[find(r[0])] = find(r[1]);

        int res = 10001;
        for (auto& r : roads)
            if (find(r[0]) == find(1))
                res = min(res, r[2]);

        return res;
    }
};
