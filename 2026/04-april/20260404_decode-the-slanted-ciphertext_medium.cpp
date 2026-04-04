/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Diagonal Traversal
 * Reconstruct the 2D grid from the encoded text using rows and derived cols (n/rows).
 * Iterate diagonally starting from each column in the first row, collecting characters
 * along each diagonal until boundaries are exceeded, then strip trailing spaces.
 *
 * Time Complexity: O(n) — each character is visited exactly once
 * Space Complexity: O(n) — for the result string
 *
 * Runtime: 15 ms
 * Memory: 38.1 MB
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
