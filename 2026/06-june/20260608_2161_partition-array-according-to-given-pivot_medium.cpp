/*
 * Problem #2161: Partition Array According to Given Pivot
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/partition-array-according-to-given-pivot/
 *
 * Approach: Three-pass partitioning using three auxiliary vectors.
 * Iterate through nums once, distributing each element into a 'less', 'equal',
 * or 'greater' bucket based on its comparison to pivot, then concatenate them.
 * This preserves relative order within each partition as required.
 *
 * Time Complexity: O(n) - single pass to partition, single pass to concatenate.
 * Space Complexity: O(n) - three auxiliary vectors store all n elements combined.
 *
 * Runtime: 17 ms
 * Memory: 143.9 MB
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
