/*
 * Problem 2747: Count Zero Request Servers
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/count-zero-request-servers/
 *
 * Approach:
 * The key insight is that processing queries in sorted order allows us to solve the problem offline using a sliding window over time. By sorting both the server logs by timestamp and the query indices by query time, the active window [q - x, q] only moves forward, allowing two pointers to incrementally add and remove logs. A frequency array tracks the number of requests for each server inside the current window alongside a counter for total unique active servers. For each query, we expand the right pointer to include logs up to time q and advance the left pointer to evict logs earlier than q - x. The answer for each query is simply the total number of servers n minus the count of currently active servers.
 *
 * Time Complexity: O(L log L + Q log Q) - Driven by sorting the logs array of length L and the queries array of length Q, while the two-pointer window traversal takes O(L + Q) total time.
 * Space Complexity: O(N + Q) - Required for the server request frequency array of size N + 1, query index sorting array, and the final answer array.
 *
 * Runtime: 55 ms | Memory: 197.9 MB
 */

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });

        vector<int> ids(queries.size());
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(),
             [&](int i, int j) { return queries[i] < queries[j]; });

        vector<int> ans(queries.size()), cnt(n + 1);
        int left = 0, right = 0, active = 0;
        for (int i : ids) {
            int q = queries[i];
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right++][0];
                if (cnt[id]++ == 0) {
                    ++active;
                }
            }
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left++][0];
                if (--cnt[id] == 0) {
                    --active;
                }
            }
            ans[i] = n - active;
        }
        return ans;
    }
};
