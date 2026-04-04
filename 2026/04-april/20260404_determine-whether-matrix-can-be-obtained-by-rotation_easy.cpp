/*
 * Determine Whether Matrix Can Be Obtained By Rotation
 * Difficulty: Easy
 * https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 *
 * Approach: Simulate all four possible 90-degree clockwise rotations of the matrix
 * and check equality with the target after each rotation. Each 90-degree clockwise
 * rotation is performed by transposing the matrix and then reversing each row.
 *
 * Time Complexity: O(n^2) - each rotation requires O(n^2) work, done at most 4 times
 * Space Complexity: O(1) - rotation is performed in-place on the input matrix
 *
 * Runtime: 0 ms
 * Memory: 14.4 MB
 */

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int r = 0; r < 4; r++) {
            if (mat == target) return true;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    swap(mat[i][j], mat[j][i]);
            for (int i = 0; i < n; i++) reverse(mat[i].begin(), mat[i].end());
        }
        return false;
    }
};
