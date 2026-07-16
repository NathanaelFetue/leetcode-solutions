/*
 * Problem #3867 - Sum of GCD of Formed Pairs
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
 *
 * Approach/Algorithm:
 * First, compute the prefix maximum array to track the running maximum up to each index.
 * Then, compute a transformed array where each element is gcd(nums[i], prefixMax[i]), capturing the relationship between each element and the maximum seen so far.
 * Finally, sort this derived array and use a two-pointer technique, pairing elements from both ends and accumulating their GCDs as the answer.
 *
 * Time Complexity: O(n log n) - dominated by sorting the prefixGcd array of size n; GCD computations are O(log(max_val)) each.
 * Space Complexity: O(n) - for the prefix maximum array and prefix GCD array, each of size n.
 *
 * Runtime: 93 ms
 * Memory: 177.3 MB
 */

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> mx;
        int prefixMax = INT_MIN;

        for (int x : nums) {
            prefixMax = max(prefixMax, x);
            mx.push_back(prefixMax);
        }

        vector<int> prefixGcd;
        for (int i = 0; i < n; ++i) {
            prefixGcd.push_back(gcd(nums[i], mx[i]));
        }

        ranges::sort(prefixGcd);

        long long ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            ++left;
            --right;
        }

        return ans;
    }
};
