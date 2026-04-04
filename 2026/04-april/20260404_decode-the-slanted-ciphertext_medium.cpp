/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Diagonal Traversal
 * Reconstruct the 2D grid from the encoded string using rows and computed columns.
 * Iterate column by column, reading diagonally (down-right) to recover the original text.
 * Strip trailing spaces from the result to match the expected output.
 *
 * Time Complexity : O(n) where n is the length of encodedText
 * Space Complexity : O(n) for the result string
 *
 * Runtime : 16 ms
 * Memory  : 38.1 MB
 */

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        string result = "";

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                result.push_back(encodedText[i * cols + j]);
                i++;
                j++;
            }
        }
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
