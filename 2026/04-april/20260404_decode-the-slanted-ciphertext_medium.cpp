/*
 * Decode the Slanted Ciphertext
 * Difficulty: Medium
 * https://leetcode.com/problems/decode-the-slanted-ciphertext/
 *
 * Approach: Matrix Diagonal Traversal
 * Reconstruct the original text by traversing the encoded text diagonally.
 * The encoded text is treated as a rows x cols matrix, and we iterate over
 * each diagonal starting from each column in the first row, reading characters
 * along the diagonal (i, j) -> (i+1, j+1). Trailing spaces are stripped at the end.
 *
 * Time Complexity:  O(n) where n is the length of encodedText
 * Space Complexity: O(n) for the result string
 *
 * Runtime: 15 ms
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
