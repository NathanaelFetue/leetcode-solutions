/*
 * 2161. Partition Array According to Given Pivot
 * Difficulty: Medium
 * https://leetcode.com/problems/partition-array-according-to-given-pivot/
 *
 * Approach: Three-pass partitioning using three separate auxiliary vectors.
 * Iterate through nums once, placing each element into a 'less', 'equal', or
 * 'greater' bucket based on its comparison with pivot, then concatenate them.
 *
 * Time Complexity: O(n) — single pass to partition, single pass to build result.
 * Space Complexity: O(n) — three auxiliary vectors collectively store all n elements.
 *
 * Runtime: 12 ms
 * Memory: 143.7 MB
 */

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int x : nums) {
            if (x < pivot)      less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else                greater.push_back(x);
        }

        vector<int> res;
        for (int x : less)    res.push_back(x);
        for (int x : equal)   res.push_back(x);
        for (int x : greater) res.push_back(x);

        return res;
    }
};
