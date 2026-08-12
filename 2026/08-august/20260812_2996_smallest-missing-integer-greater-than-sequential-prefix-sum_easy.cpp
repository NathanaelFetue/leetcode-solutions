/*
 * Problem 2996: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
 *
 * Approach: Calculate the sum of the longest sequential prefix starting from the first element. Store all elements of the array in a hash set for O(1) lookups. Beginning with the prefix sum, incrementally check for its existence in the hash set, adding 1 until finding the smallest missing integer.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * Runtime: 0 ms
 * Memory: 22.8 MB
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
