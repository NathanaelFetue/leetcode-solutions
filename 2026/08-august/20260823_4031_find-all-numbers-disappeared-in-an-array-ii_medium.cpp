/*
 * Problem 4031: Find All Numbers Disappeared in an Array II
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/
 *
 * Approach:
 * The key insight is that sorting the array allows us to sequentially scan for missing intervals by maintaining a running pointer (`cur`) initialized to the `lower` bound. As we iterate through the sorted numbers, we ignore duplicates or values below `cur` and terminate early once we exceed `upper`. Any element strictly greater than `cur` reveals a disappeared contiguous range from `cur` to `x - 1`, which we record before advancing `cur` to `x + 1`. This sorting-based sequential scanning guarantees we identify all gaps in a single pass without the high memory overhead of hash sets.
 *
 * Time Complexity: O(N log N) — Driven by sorting the input array `nums` of size N, while the subsequent gap scanning runs in a single linear pass of O(N).
 * Space Complexity: O(1) — Operating in-place on the input array, requiring only O(1) auxiliary space (excluding the memory used by the sorting algorithm's recursion stack and the returned result).
 *
 * Runtime: 100 ms | Memory: 242.3 MB
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
