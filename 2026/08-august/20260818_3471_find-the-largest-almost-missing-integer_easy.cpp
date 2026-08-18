/*
 * Problem 3471: Find the Largest Almost Missing Integer
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/find-the-largest-almost-missing-integer/
 *
 * Approach:
 * The key insight is to track how many unique subarrays (windows) of size k contain each integer, ensuring that duplicates within any single window are not double-counted. We achieve this by iterating through all possible fixed-size sliding windows of length k and using an auxiliary hash set to deduplicate elements inside the current window. These unique elements are then used to increment a global frequency map that records the number of windows containing each value. Finally, we scan the frequency map to find the maximum element that appeared in exactly one window, returning -1 if no such element exists.
 *
 * Time Complexity: O(N * K) — where N is the number of elements in the array and K is the window size. There are N - K + 1 sliding windows, and for each window, we perform O(K) average-time operations to deduplicate its elements and update their global window counts.
 * Space Complexity: O(N) — driven by the global frequency map which stores up to N unique elements, alongside the auxiliary hash set which requires at most O(K) space for deduplicating elements in a single window.
 *
 * Runtime: 15 ms | Memory: 32.6 MB
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
