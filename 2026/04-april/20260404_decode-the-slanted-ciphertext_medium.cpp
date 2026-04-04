/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Reconstruction + Diagonal Traversal
 * First, reconstruct the encoded text into a rows x cols matrix. Then, for each
 * starting column, traverse diagonally (one row down, one column right) to read
 * off the original plaintext characters, and finally strip any trailing spaces.
 *
 * Time Complexity:  O(rows * cols) for both matrix fill and diagonal traversal
 * Space Complexity: O(rows * cols) for the auxiliary matrix
 *
 * Runtime: 56 ms
 * Memory:  49.1 MB
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
