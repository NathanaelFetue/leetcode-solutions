/*
 * Problem #739 - Daily Temperatures
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/daily-temperatures/
 *
 * Approach: Monotonic Stack
 * We maintain a monotonic decreasing stack of indices representing days with unresolved temperatures.
 * For each day i, we pop indices from the stack while the current temperature is warmer than the temperature
 * at the top index, computing the waiting days as (i - popped_index). Remaining indices in the stack
 * never find a warmer day and stay at 0 in the result.
 *
 * Time Complexity: O(n) - each index is pushed and popped from the stack at most once.
 * Space Complexity: O(n) - the stack can hold at most n indices in the worst case (monotonically decreasing input).
 *
 * Runtime: 20 ms
 * Memory: 107.5 MB
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
