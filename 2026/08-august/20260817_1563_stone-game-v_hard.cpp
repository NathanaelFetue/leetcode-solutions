/*
 * Problem 1563: Stone Game V
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/stone-game-v/
 *
 * Approach:
 * The key insight is to model the game as an interval dynamic programming problem, where we compute the maximum score Alice can achieve for any subarray `stoneValue[left...right]`. Since Bob's choice of which group to discard is deterministic (he always forces Alice to keep the group with the smaller sum), Alice's optimal strategy depends entirely on choosing the split point that maximizes her potential return. We use top-down recursion with memoization to exhaustively partition the subarray, recursively solving the subproblem of the retained group and caching the results to avoid redundant calculations. This allows us to transition optimally based on the relative sums of the left and right segments.
 *
 * Time Complexity: O(N^3) — There are O(N^2) total states representing all possible subarrays. For each state, we iterate through O(N) possible split points and compute interval sums, making the state transition cost linear, which leads to an overall cubic time complexity.
 * Space Complexity: O(N^2) — The memoization table of size N x N stores the optimal results for each subarray, and the recursion stack uses up to O(N) space.
 *
 * Runtime: 612 ms | Memory: 27.6 MB
 */

class Solution {
private:
    vector<vector<int>> f;

public:
    int dfs(const vector<int>& stoneValue, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (f[left][right]) {
            return f[left][right];
        }

        int sum = accumulate(stoneValue.begin() + left,
                             stoneValue.begin() + right + 1, 0);
        int suml = 0;
        for (int i = left; i < right; ++i) {
            suml += stoneValue[i];
            int sumr = sum - suml;
            if (suml < sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, left, i) + suml);
            } else if (suml > sumr) {
                f[left][right] =
                    max(f[left][right], dfs(stoneValue, i + 1, right) + sumr);
            } else {
                f[left][right] =
                    max(f[left][right], max(dfs(stoneValue, left, i),
                                            dfs(stoneValue, i + 1, right)) +
                                            suml);
            }
        }
        return f[left][right];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        f.assign(n, vector<int>(n));
        return dfs(stoneValue, 0, n - 1);
    }
};
