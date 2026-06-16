/*
 * Problem #868 - Binary Gap
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/binary-gap/
 *
 * Approach/Algorithm:
 * Convert the integer to its 32-bit binary string representation using bitset.
 * Iterate through the binary string, tracking the index of the last seen '1' bit.
 * For each new '1' found, compute the distance from the previous '1' and update the maximum gap.
 *
 * Time Complexity: O(1) - The binary string is always 32 characters long (fixed-size bitset),
 * so the loop runs a constant number of iterations regardless of input.
 *
 * Space Complexity: O(1) - Only a fixed 32-character string and two integer variables are used.
 *
 * Runtime: 0 ms
 * Memory: 8.1 MB
 */

class Solution {
public:
    int binaryGap(int n) {
        string bits = bitset<32>(n).to_string();
        int cpt = 0, lastPos = -1;

        for (int i = 0; i < bits.length(); i++) {
            if (bits[i] == '1') {
                if (lastPos != -1) cpt = max(cpt, i - lastPos);
                lastPos = i;
            }
        }
        return cpt;
    }
};
