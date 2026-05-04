/*
 * Problem: Rotate Image
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotate-image/
 *
 * Approach: Transpose + Reverse Rows (In-Place 90° Clockwise Rotation)
 * The matrix is first transposed by swapping elements across the main diagonal (matrix[i][j] <-> matrix[j][i]).
 * After transposition, each row is reversed to achieve the 90-degree clockwise rotation.
 * This two-step approach avoids using extra space and completes the rotation in-place.
 *
 * Time Complexity: O(n²) — Every element in the n×n matrix is visited during both the transpose and reverse steps.
 * Space Complexity: O(1) — The rotation is performed in-place with no additional data structures.
 *
 * Runtime: 0 ms
 * Memory: 10.2 MB
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i=0; i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
