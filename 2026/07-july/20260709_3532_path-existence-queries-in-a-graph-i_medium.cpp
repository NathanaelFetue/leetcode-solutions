/*
 * Problem #3532 - Path Existence Queries in a Graph I
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
 *
 * Approach: Connected Component Labeling via Linear Scan
 * Since the array is sorted and edges only exist between nodes i and j where
 * nums[j] - nums[i] <= maxDiff, consecutive nodes with a difference exceeding
 * maxDiff form a boundary between connected components. We assign each node
 * a component ID in a single pass, then answer each query in O(1) by comparing
 * the component IDs of the two query nodes.
 *
 * Time Complexity: O(n + q) - one pass to label n nodes, one pass over q queries
 * Space Complexity: O(n + q) - component array of size n, output array of size q
 *
 * Runtime: 14 ms
 * Memory: 224.1 MB
 */

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int compNo = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                compNo++;
            }
            component[i] = compNo;
        }
        vector<bool> sol;

        for(auto &it : queries){
            sol.push_back(component[it[0]] == component[it[1]]);
        }

        return sol;
    }
};
