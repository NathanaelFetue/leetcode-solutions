/*
 * Problem 3471: Find the Largest Almost Missing Integer
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
 *
 * Approach:
 * The key insight is to track the window-level frequency of each unique element across all possible subarrays of length k. An integer is "almost missing" if it appears in exactly one of these subarrays. We simulate this by shifting a window of size k across the array, deduplicating elements within the current window using a hash set, and then updating a global frequency map that counts how many windows each element belongs to. Finally, we scan the frequency map to find the maximum element with a frequency of exactly one.
 *
 * Time Complexity: O((N - K) * K) — driven by processing each of the N - K + 1 sliding windows of size K, deduplicating its elements, and updating their global frequencies in a hash map.
 * Space Complexity: O(N) — driven by the global hash map storing window frequencies for up to N unique elements and the temporary hash set storing up to K elements per window.
 *
 * Runtime: 18 ms | Memory: 32.7 MB
 */

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> numWindows;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen; // dedupliquer par fenetre
            for (int j = i; j < i + k; j++)
                seen.insert(nums[j]);
            for (int x : seen)
                numWindows[x]++;
        }

        int ans = -1;
        for (auto& [val, cnt] : numWindows)
            if (cnt == 1) ans = max(ans, val);

        return ans;
    }
};
