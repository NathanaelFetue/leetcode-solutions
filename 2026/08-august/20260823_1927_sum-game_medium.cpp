/*
 * Problem 1927: Sum Game
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/sum-game/
 *
 * Approach:
 * The key insight is that Bob can force a win if and only if he can pair up the '?' moves to perfectly neutralize Alice's strategy. By using a symmetric game-theory pairing strategy, Bob can guarantee that any pair of '?' marks on the same side contributes exactly 9 to the sum (if Alice plays x, Bob plays 9-x), which averages to 4.5 per '?'. Conversely, '?' marks on opposite sides can be neutralized to a net difference of 0 by Bob mirroring Alice's moves. Thus, Alice wins unless the initial sum deficit on one side is perfectly balanced by the excess '?' marks on the other side at a rate of 4.5 per '?'.
 *
 * Time Complexity: O(N) — a single linear scan of the string of length N to count '?' characters and accumulate digit sums on both halves.
 * Space Complexity: O(1) — only constant auxiliary space is used for the sum and question mark counters.
 *
 * Runtime: 3 ms | Memory: 14 MB
 */

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

