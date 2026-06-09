/*
 * Problem #3689 - Maximum Total Subarray Value I (Medium)
 * https://leetcode.com/problems/maximum-total-subarray-value-i/
 *
 * Approach: Greedy / Math Observation
 * The maximum total value across all subarrays of length k is achieved by maximizing
 * the difference between the maximum and minimum elements in the array multiplied by k.
 * Since we can choose any subarray of length k, the optimal strategy is to pair the global
 * maximum with the global minimum, yielding k * (maxVal - minVal).
 *
 * Time Complexity: O(n)
 *   - Two linear scans to find the global maximum and minimum values.
 *
 * Space Complexity: O(1)
 *   - Only two integer variables are used regardless of input size.
 *
 * Runtime: 0 ms | Memory: 103.8 MB
 */

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        return (long long)k * (maxVal - minVal);
    }
};
