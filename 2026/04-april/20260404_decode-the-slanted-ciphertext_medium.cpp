/*
 * Problem: Decode the Slanted Ciphertext
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach/Algorithm:
 * First, reconstruct the 2D matrix from the encoded text by filling it row by row.
 * Then, traverse the matrix diagonally starting from each column in the first row,
 * collecting characters along each diagonal to reconstruct the original plaintext.
 * Finally, strip any trailing spaces from the result.
 *
 * Time Complexity: O(rows * cols) — linear in the size of the encoded text
 * Space Complexity: O(rows * cols) — for the intermediate 2D matrix
 *
 * Runtime: 47 ms
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
