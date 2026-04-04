/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Diagonal Traversal
 * The encoded text is reshaped into a rows x cols matrix. We then read diagonals
 * starting from each column of the first row, collecting characters along each
 * diagonal until we go out of bounds, then strip trailing spaces from the result.
 *
 * Time Complexity:  O(n) where n is the length of encodedText
 * Space Complexity: O(n) for the result string
 *
 * Runtime: 23 ms
 * Memory:  38.2 MB
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
