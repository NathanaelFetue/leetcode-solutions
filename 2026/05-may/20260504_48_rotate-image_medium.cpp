/*
 * Problem #48 - Rotate Image
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotate-image/
 *
 * Approach: In-place matrix rotation using transpose + horizontal flip.
 * First, transpose the matrix by swapping matrix[i][j] with matrix[j][i] for all i < j.
 * Then reverse each row to achieve a 90-degree clockwise rotation without extra space.
 *
 * Time Complexity: O(n^2) — every cell is visited once during transpose and once during row reversal.
 * Space Complexity: O(1) — the rotation is performed in-place with no additional data structures.
 *
 * Runtime: 0 ms
 * Memory: 10.3 MB
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        // inverser chaque ligne
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
