/*
 * Problem #739: Daily Temperatures (Medium)
 * https://leetcode.com/problems/daily-temperatures/
 *
 * Approach: Monotonic Stack
 * We use a monotonic decreasing stack that stores indices of temperatures.
 * For each new temperature, we pop all stack entries with a lower temperature,
 * calculating the wait days as the difference between the current and stored index.
 * Remaining indices in the stack never find a warmer day and stay 0 in the result.
 *
 * Time Complexity: O(n) - each index is pushed and popped at most once.
 * Space Complexity: O(n) - stack can hold up to n indices in the worst case.
 *
 * Runtime: 23 ms
 * Memory: 107.4 MB
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top(); st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        return result;
    }
};
