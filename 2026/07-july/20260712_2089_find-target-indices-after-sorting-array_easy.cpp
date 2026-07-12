/*
 * Problem 2089: Find Target Indices After Sorting Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-target-indices-after-sorting-array/
 *
 * Approach: Sort the array, then use binary search (lower_bound and upper_bound)
 * to find the range of indices where the target value exists. Iterate over
 * that range and collect the 0-based indices into the result vector.
 *
 * Time Complexity: O(n log n) - dominated by sorting; binary search is O(log n)
 * and the iteration over matching elements is at most O(n).
 *
 * Space Complexity: O(n) - output vector can hold up to n indices in the worst
 * case where all elements equal the target; no extra auxiliary space used.
 *
 * Runtime: 0 ms
 * Memory: 15.1 MB
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        vector<int> tarIdx;

        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        for (auto it = first; it != last; ++it)
            tarIdx.push_back(it - nums.begin());

        return tarIdx;
    }
};
