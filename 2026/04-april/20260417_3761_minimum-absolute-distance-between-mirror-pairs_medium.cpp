/*
 * Problem #3761 - Minimum Absolute Distance Between Mirror Pairs
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
 *
 * Approach: Hash Map with Digit Reversal
 * For each number, we check if its digit-reversed counterpart has been seen before (stored in a hash map).
 * When a match is found (nums[i] is the reverse of a previously seen number), we compute the index distance and track the minimum.
 * We store the reversed form of each number mapped to its index, so future numbers can look themselves up as potential mirror partners.
 *
 * Time Complexity: O(n * d) where n is the number of elements and d is the max number of digits (at most 10), effectively O(n).
 * Space Complexity: O(n) for the hash map storing up to n entries.
 *
 * Runtime: 113 ms
 * Memory: 131.9 MB
 */

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]))
                res = min(res, i - mp[nums[i]]);
            mp[reverse(nums[i])] = i;
        }
        return res == INT_MAX ? -1 : res;
    }    
};
