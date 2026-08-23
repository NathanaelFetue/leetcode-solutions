/*
 * Problem 4031: Find All Numbers Disappeared in an Array II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
 *
 * Approach:
 * The key insight is to sort the input array to process elements in increasing order, transforming the search for missing ranges into a sequential boundary-tracking task. By maintaining a pointer `cur` initialized to `lower` that tracks the next expected integer in the range, we can identify missing gaps whenever we encounter an element `x` strictly greater than `cur`. This sorted interval tracking technique allows us to greedily construct missing sub-ranges `[cur, x - 1]` in a single linear scan while naturally ignoring duplicate values and elements outside the boundaries.
 *
 * Time Complexity: O(N log N) — dominated by the initial sorting of the input array, followed by a linear scan of O(N) to identify the missing intervals.
 * Space Complexity: O(1) — using constant auxiliary space besides the output buffer, assuming the sorting algorithm operates in-place (or O(log N) space for the recursive call stack of the sorting algorithm).
 *
 * Runtime: 113 ms | Memory: 242.3 MB
 */

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int cur = lower;

        for (int x : nums) {
            if (x < cur) continue;   
            if (x > upper) break;
            if (x > cur)
                res.push_back({cur, x - 1}); 
            cur = x + 1; 
        }

        if (cur <= upper)
            res.push_back({cur, upper});

        return res;
    }
};
