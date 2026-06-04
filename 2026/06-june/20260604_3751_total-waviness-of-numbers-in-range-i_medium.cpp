/*
 * Problem #3751 - Total Waviness of Numbers in Range I (Medium)
 * URL: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
 *
 * Approach/Algorithm:
 * For each integer in [num1, num2], convert it to a string and scan every middle
 * digit (index 1 to len-2) to check if it forms a peak (greater than both neighbors)
 * or a valley (less than both neighbors). Each such digit increments the waviness
 * count, and all individual waviness values are summed for the final result.
 *
 * Time Complexity: O((num2 - num1) * D) where D is the number of digits (~10 max),
 * effectively O(num2 - num1) for the given constraints.
 *
 * Space Complexity: O(D) for the string representation of each number, O(1) overall.
 *
 * Runtime: 57 ms
 * Memory: 10.3 MB
 */

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        auto getWaviness = [](int x) -> int {
            string s = to_string(x);
            int waviness = 0;

            for (size_t i = 1; i < s.size() - 1; ++i) {
                bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
                bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
                if (isPeak || isValley) {
                    ++waviness;
                }
            }

            return waviness;
        };

        int total = 0;
        for (int i = num1; i <= num2; ++i) {
            total += getWaviness(i);
        }

        return total;
    }
};
