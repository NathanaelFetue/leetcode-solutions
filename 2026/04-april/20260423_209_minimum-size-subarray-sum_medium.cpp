/*
 * Problem 209: Minimum Size Subarray Sum (Medium)
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 *
 * Approach: Sliding Window
 * Use a two-pointer sliding window where the right pointer expands the window by adding
 * elements to a running sum. Once the sum meets or exceeds the target, the left pointer
 * shrinks the window while recording the minimum length, until the sum drops below target.
 *
 * Time Complexity: O(n) - Each element is added and removed from the window at most once,
 * resulting in at most 2n operations across the entire traversal.
 *
 * Space Complexity: O(1) - Only a constant number of variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 32.1 MB
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, best = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                best = min(best, right - left + 1);
                sum -= nums[left++];
            }
        }
        return best == INT_MAX ? 0 : best;
    }
};
