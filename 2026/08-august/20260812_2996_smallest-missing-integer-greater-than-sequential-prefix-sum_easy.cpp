/*
 * Problem 2996: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/
 *
 * Approach:
 * The key insight is to separate the problem into two distinct phases: finding the sum of the longest sequential prefix and then resolving collisions against the existing elements. By definition, a sequential prefix must start at index 0 and increment by exactly 1 at each step. We calculate this prefix sum in a single linear pass that terminates immediately upon encountering a non-sequential element. Utilizing a hash set for O(1) lookups allows us to efficiently increment this sum until we find the smallest integer not present in the original array.
 *
 * Time Complexity: O(N) — Populating the hash set and calculating the sequential prefix sum takes O(N) time, followed by at most O(N) lookup operations to find the smallest missing integer.
 * Space Complexity: O(N) — An unordered set is used to store the unique elements of the input array for O(1) lookup performance.
 *
 * Runtime: 0 ms | Memory: 23.1 MB
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
