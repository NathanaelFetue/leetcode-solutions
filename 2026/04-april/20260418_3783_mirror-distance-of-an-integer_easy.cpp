/*
 * Problem #3783: Mirror Distance of an Integer
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/mirror-distance-of-an-integer/
 *
 * Approach/Algorithm:
 * Extract the digits of n into a vector by repeatedly taking the remainder mod 10,
 * which naturally stores digits in reverse (least significant first). Then reconstruct
 * a new integer by reading the vector from front to back, effectively reversing the digits.
 * Finally, return the absolute difference between the original number and its mirror (reversed) number.
 *
 * Time Complexity: O(d) where d is the number of digits in n (at most 10 for a 32-bit integer).
 * Space Complexity: O(d) for the digit vector storing up to d digits.
 *
 * Runtime: 0 ms
 * Memory: 9 MB
 */

class Solution {
public:
    int mirrorDistance(int n) {
        vector<int> num;
        int tmp = n;
        while (tmp > 0) {
            num.push_back(tmp % 10);
            tmp /= 10;
        }
        int newNum = 0;
        for (int i = 0; i < num.size(); i++)
            newNum = newNum * 10 + num[i];
        return abs(n - newNum);
    }
};
