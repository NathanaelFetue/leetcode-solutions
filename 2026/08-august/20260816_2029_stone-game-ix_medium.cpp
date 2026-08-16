/*
 * Problem 2029: Stone Game IX
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/stone-game-ix/
 *
 * Approach:
 * The key insight is that stones are only distinguished by their values modulo 3, and players must avoid making the cumulative sum divisible by 3. Using combinatorial game theory with modular arithmetic, we classify stones into three categories based on their remainders. Stones with a remainder of 0 act as "pass" moves that shift turn parity without changing the running sum modulo 3. If the count of 0-remainder stones is even, they effectively cancel out, allowing Alice to win if she has at least one of both remainder 1 and 2 to choose the winning path. If the count is odd, the turn parity flips, enabling Alice to win only if she has a substantial surplus (difference greater than 2) of one remainder type to overwhelm Bob's defensive play.
 *
 * Time Complexity: O(N) — one linear scan of the input array to count the frequency of each remainder class.
 * Space Complexity: O(1) — constant auxiliary space is used to store the three remainder counters.
 *
 * Runtime: 0 ms | Memory: 131.4 MB
 */

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val : stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            } else if (type == 1) {
                ++cnt1;
            } else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};
