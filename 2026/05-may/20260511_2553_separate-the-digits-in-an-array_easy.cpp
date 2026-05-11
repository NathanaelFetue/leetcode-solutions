/*
 * Problem #2553: Separate the Digits in an Array
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/separate-the-digits-in-an-array/
 *
 * Approach/Algorithm:
 * For each number in the input array, extract its individual digits using repeated
 * modulo and integer division operations (e % 10 and e / 10). Since this extracts
 * digits in reverse order (least significant first), they are stored temporarily
 * and then appended to the result in reverse order to preserve original digit ordering.
 *
 * Time Complexity: O(n * d), where n is the number of elements in nums and d is
 * the average number of digits per element (at most 9 for standard integers).
 *
 * Space Complexity: O(n * d) for the result array storing all separated digits,
 * plus O(d) auxiliary space for the temporary digit buffer per element.
 *
 * Runtime: 8 ms | Memory: 16 MB
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> res;

        for(int e : nums) {
            vector <int> digit;
            while(e >0) {
                digit.push_back(e%10);
                e= e/10;
            }
            for(int i =digit.size()-1; i>=0; i--) {
                res.push_back(digit[i]);
            }
        }
        return res;
    }
};
