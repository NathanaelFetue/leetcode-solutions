/*
 * Problem 2996: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
 *
 * Approach:
 * The key insight is to decouple the problem into finding the sequential prefix sum and searching for the smallest missing integer. We greedily accumulate consecutive elements starting from the first element as long as the sequential relationship (nums[i] == nums[i-1] + 1) holds. To optimize the subsequent search, we populate a hash set containing all array elements. This allows us to increment the sequential prefix sum iteratively and verify its existence in the set in O(1) time, guaranteeing we find the smallest missing integer in at most N steps.
 *
 * Time Complexity: O(N) — One linear scan is performed to build the hash set and determine the sequential prefix sum. The subsequent search increments the prefix sum and checks existence in the set in O(1) time, running at most N times since there are at most N unique elements.
 * Space Complexity: O(N) — An unordered hash set stores up to N elements of the input array to facilitate constant-time lookup checks during the sequential missing integer search.
 *
 * Runtime: 2 ms | Memory: 23.1 MB
 */

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }

        while (num_set.count(total)) {
            total += 1;
        }

        return total;
    }
};
