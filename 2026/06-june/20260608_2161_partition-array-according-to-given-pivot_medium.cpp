/*
 * Problem #2161: Partition Array According to Given Pivot
 * Difficulty: Medium
 * https://leetcode.com/problems/partition-array-according-to-given-pivot/
 *
 * Approach: Three-Pass Partitioning with Auxiliary Arrays
 * Iterate through the input array once, distributing each element into one of three
 * buckets: less than pivot, equal to pivot, or greater than pivot. Then concatenate
 * the three buckets in order to form the final result array.
 *
 * Time Complexity: O(n) — single pass to partition and single pass to build result,
 * where n is the number of elements in nums.
 *
 * Space Complexity: O(n) — three auxiliary vectors collectively store all n elements
 * before being merged into the result array.
 *
 * Runtime: 12 ms | Memory: 143.8 MB
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
