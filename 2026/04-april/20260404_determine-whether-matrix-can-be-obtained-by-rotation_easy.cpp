/*
 * Determine Whether Matrix Can Be Obtained By Rotation
 * Difficulty : Easy
 * https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 *
 * Approach : Simulate all four 90-degree rotations of the matrix in-place and
 * check equality with the target after each rotation. Each 90-degree clockwise
 * rotation is performed by transposing the matrix and then reversing each row.
 *
 * Time Complexity  : O(n^2) per rotation, O(n^2) overall for constant 4 rotations
 * Space Complexity : O(1) extra space (in-place rotation)
 *
 * Runtime : 0 ms
 * Memory  : 14.5 MB
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
