/*
 * Problem #1665 - Minimum Initial Energy to Finish Tasks
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
 *
 * Approach: Greedy with custom sorting by gap (minimum - actual) in descending order.
 * Tasks with a larger gap between their minimum requirement and actual cost are done first,
 * as they are the most restrictive in terms of upfront energy needed.
 * We then simulate backwards from the last task, accumulating the minimum required energy.
 *
 * Algorithm:
 * - Sort tasks by (min - actual) descending
 * - Iterate in reverse, updating energy as max(energy + actual, minimum)
 *
 * Time Complexity: O(n log n) — dominated by the sort step over n tasks
 * Space Complexity: O(1) — sorting in-place, only a single integer accumulator used
 *
 * Runtime: 39 ms | Memory: 97.2 MB
 */

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Tri par gap = min - actual décroissant
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int energy = 0;
        for (int i = tasks.size() - 1; i >= 0; i--) {
            energy = max(energy + tasks[i][0], tasks[i][1]);
        }
        return energy;
    }
};
