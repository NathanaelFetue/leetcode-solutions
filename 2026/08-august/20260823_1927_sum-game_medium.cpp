/*
 * Problem 1927: Sum Game
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sum-game/
 *
 * Approach:
 * The key insight is reducing the game to a balancing act using game theory and symmetric play. Since Alice and Bob play optimally, Bob can always counter Alice's moves: any pair of question marks on opposite sides can cancel each other out, and any pair of question marks on the same side can be forced by Bob to sum to exactly 9 by playing the complement (9 - x) of whatever Alice plays. This effectively values each net question mark at 4.5. Consequently, Bob wins if and only if the deficit between the two halves' sums is perfectly balanced by the net difference in question marks valued at 4.5 each.
 *
 * Time Complexity: O(N) — a single linear scan of the string to accumulate the sums and count the question marks in both halves.
 * Space Complexity: O(1) — only a few integer counters are used, requiring constant auxiliary space.
 *
 * Runtime: 3 ms | Memory: 14 MB
 */

#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < n; i++) {
            if (i < mid) {
                if (num[i] == '?') qL++;
                else sumL += num[i] - '0';
            } else {
                if (num[i] == '?') qR++;
                else sumR += num[i] - '0';
            }
        }
        return (sumL - sumR) != (qR - qL) * 4.5;
    }
};

