/*
 * Problem #3020: Find the Maximum Number of Elements in Subset
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/
 *
 * Approach: Frequency counting with exponential chain traversal.
 * For each unique base number, we greedily extend a subset pattern [x, x^2, x^4, ..., x^(2^k), ..., x^4, x^2, x]
 * by squaring the current value and checking if it appears more than once in the frequency map.
 * Ones are handled separately since 1^2 = 1; the max valid odd count of 1s anchors the minimum answer.
 *
 * Time Complexity: O(n log log M) where n is the number of elements and M is the max value,
 * because each chain grows exponentially via squaring, resulting in at most log log M steps per base.
 * Space Complexity: O(n) for the frequency hash map storing counts of all unique elements.
 *
 * Runtime: 87 ms
 * Memory: 122.8 MB
 */

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int ans = 0;
        // ans is at least the number of occurrences of 1, rounded down to an
        // odd number
        if (cnt[1] % 2 == 0) {
            ans = cnt[1] - 1;
        } else {
            ans = cnt[1];
        }
        cnt.erase(1);
        for (auto& [num, _] : cnt) {
            int res = 0;
            long long x = num;
            for (; cnt.contains(x) && cnt[x] > 1; x *= x) {
                res += 2;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }
        return ans;
    }
};
