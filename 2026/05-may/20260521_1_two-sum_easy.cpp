/*
 * Problem #1 - Two Sum (Easy)
 * LeetCode URL: https://leetcode.com/problems/two-sum/
 *
 * Approach: Hash Map (One-Pass)
 * Iterate through the array once, checking at each element whether its complement
 * (target - nums[i]) already exists in the hash map. If found, return the stored
 * index of the complement and the current index. Otherwise, store the current
 * element and its index in the map for future lookups.
 *
 * Time Complexity : O(n) - Single pass through the array; each lookup and
 *                   insertion in the unordered_map is O(1) on average.
 * Space Complexity: O(n) - In the worst case, all n elements are stored in the
 *                   hash map before a valid pair is found.
 *
 * Runtime : 0 ms
 * Memory  : 14.8 MB
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int ,int> mp;

        for(int i=0; i<nums.size(); i++) {
            if ( mp.contains(target - nums[i])) {
                return {mp[target -nums[i]] , i};
            } 
            mp[nums[i]] = i;
        }
        return {};
    }
};

