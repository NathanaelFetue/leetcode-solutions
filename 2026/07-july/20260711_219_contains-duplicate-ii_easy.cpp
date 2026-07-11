/*
 * Problem #219 - Contains Duplicate II (Easy)
 * https://leetcode.com/problems/contains-duplicate-ii/
 *
 * Approach: Hash Map (Index Tracking)
 * Iterate through the array while maintaining a hash map that stores each element's
 * most recent index. For each element, check if it already exists in the map and
 * whether the distance between the current index and its stored index is within k.
 * If so, return true; otherwise, update the map with the current index.
 *
 * Time Complexity : O(n) - single pass through the array of n elements
 * Space Complexity: O(n) - hash map stores at most n unique elements
 *
 * Runtime : 66 ms
 * Memory  : 98.6 MB
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && abs(i - mp[nums[i]]) <= k)
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};
