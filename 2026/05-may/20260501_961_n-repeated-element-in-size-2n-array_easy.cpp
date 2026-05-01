/*
 * Problem #961: N-Repeated Element in Size 2N Array (Easy)
 * https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
 *
 * Approach: Hash Map First-Occurrence Detection
 * Iterate through the array while tracking seen elements in an unordered_map.
 * The first time a duplicate is encountered during traversal, it must be the
 * element repeated N times (since all other elements appear exactly once),
 * so we immediately return it.
 *
 * Time Complexity: O(n) - single pass through the array of size 2N.
 * Space Complexity: O(n) - hash map stores at most N+1 unique elements
 * before the repeated element is found.
 *
 * Runtime: 0 ms
 * Memory: 28.5 MB
 */

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map <int , int> mp;
        mp[nums[0]] = 1;
        for(int i =1; i<nums.size(); i++) {
            if( mp.count(nums[i]) >0) return nums[i];
            mp[nums[i]] = 1;
        }
        return 0;
    }
};
