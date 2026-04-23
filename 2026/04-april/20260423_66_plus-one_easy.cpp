/*
 * Problem #66 - Plus One (Easy)
 * https://leetcode.com/problems/plus-one/
 *
 * Approach: Recursive carry propagation.
 * If the last digit is not 9, simply increment it and return. If it is 9, set it to 0
 * and recursively apply plusOne to the remaining prefix, handling carry propagation
 * up the digits. If only one digit remains and it is 9, prepend a 1 to handle overflow.
 *
 * Time Complexity: O(n) in the worst case (e.g., [9,9,9,...,9]) where n is the
 * number of digits, as every digit may need to be visited once through recursion.
 *
 * Space Complexity: O(n) due to the recursive call stack and subarray copies
 * created at each level of recursion, proportional to the number of digits.
 *
 * Runtime: 0 ms | Memory: 12.3 MB
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] != 9) {
            digits[n-1]++;
            return digits;
        }
        digits[n-1] = 0;
        if (n == 1) {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        vector<int> sub(digits.begin(), digits.end() - 1);
        sub = plusOne(sub);
        sub.push_back(0);
        return sub;
    }
};
