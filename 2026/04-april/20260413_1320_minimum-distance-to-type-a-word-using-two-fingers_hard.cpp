/*
 * Problem #1320: Minimum Distance to Type a Word Using Two Fingers (Hard)
 * URL: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
 *
 * Approach: Dynamic Programming with two-finger state compression.
 * The DP state dp[j] represents the minimum cost to type all characters up to the
 * current one, where one finger is at the current character and the other finger is
 * at position j (26 = unplaced/neutral). At each step, we decide which finger moves
 * to type the next character, keeping track of the stationary finger's position.
 *
 * Keyboard Layout: 26 letters mapped to a 5x6 grid; Manhattan distance is used
 * to compute movement cost between any two character positions.
 *
 * Time Complexity : O(N * 27) = O(N), where N is the length of the word.
 * Space Complexity: O(27) = O(1), only two DP arrays of fixed size 27 are used.
 *
 * Runtime : 2 ms
 * Memory  : 9.6 MB
 */

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        auto pos = [](char c) -> pair<int,int> {
            int v = c - 'A';
            return {v / 6, v % 6};
        };
        
        auto dist = [&](int a, int b) -> int {
            if (a == 26 || b == 26) return 0;
            auto [x1,y1] = pos('A' + a);
            auto [x2,y2] = pos('A' + b);
            return abs(x1-x2) + abs(y1-y2);
        };
        
        vector<int> dp(27, INT_MAX);
        dp[26] = 0;
        
        for (int k = 0; k < n; k++) {
            int cur = word[k] - 'A';
            int prev = (k == 0) ? 26 : word[k-1] - 'A';
            vector<int> ndp(27, INT_MAX);
            
            for (int j = 0; j <= 26; j++) {
                if (dp[j] == INT_MAX) continue;
            
                int cost1 = dp[j] + dist(prev, cur);
                ndp[j] = min(ndp[j], cost1);

                int cost2 = dp[j] + dist(j, cur);
                ndp[prev] = min(ndp[prev], cost2);
            }
            dp = ndp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
