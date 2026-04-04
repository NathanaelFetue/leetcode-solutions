/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Reconstruction + Diagonal Traversal
 * First, reconstruct the encoded text into a rows x cols matrix.
 * Then traverse diagonals starting from each column in the first row,
 * collecting characters along the diagonal (i, j+i offsets) to rebuild the original string.
 * Finally, strip trailing spaces from the result.
 *
 * Time Complexity: O(rows * cols) for matrix fill and diagonal traversal
 * Space Complexity: O(rows * cols) for the matrix storage
 *
 * Runtime: 43 ms
 * Memory: 49 MB
 */

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size()/rows;
        vector<vector<char>> mat(rows , vector<char>(cols));
        int index = 0;
        for(int i=0;i< rows; i++) {
            for (int j=0; j< cols; j++){
                mat[i][j] = encodedText[index++];
            }
        }
        string result = "";
        for (int j=0; j< cols; j++) {
            int k = j;
            for (int i = 0; i < rows && k < cols; i++) {
                result.push_back(mat[i][k]);
                k++;
            }

        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};
