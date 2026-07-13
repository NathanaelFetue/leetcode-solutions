/*
 * Problem #239 - Sliding Window Maximum (Hard)
 * https://leetcode.com/problems/sliding-window-maximum/
 *
 * Approach: Monotonic Deque (Decreasing)
 * A deque stores indices of elements in decreasing order of their values.
 * For each new element, we remove indices outside the window from the front,
 * and pop from the back any indices whose values are smaller than the current element,
 * ensuring the front always holds the index of the maximum in the current window.
 *
 * Time Complexity: O(n) - each element is pushed and popped from the deque at most once.
 * Space Complexity: O(k) - the deque holds at most k indices at any point.
 *
 * Runtime: 28 ms
 * Memory: 139.2 MB
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for (int r = 0; r < nums.size(); r++) {
            if (!dq.empty() && dq.front() < r - k + 1)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[r])
                dq.pop_back();

            dq.push_back(r);
            if (r >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
