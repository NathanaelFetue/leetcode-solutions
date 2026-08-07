/*
 * Problem #3348 - Smallest Divisible Digit Product II
 * Difficulty: Hard
 * URL: https://leetcode.com/problems/smallest-divisible-digit-product-ii/
 *
 * Approach: First verify t is factorable using only digits 2-9; if not, return -1.
 * Then greedily check if the original number already satisfies the condition by
 * tracking remaining divisibility requirements left to right using GCD reduction.
 * If not satisfied, backtrack from the rightmost valid position, incrementing digits
 * and greedily filling remaining positions with the largest valid digits (2-9).
 * If no valid number of the same length exists, construct the smallest (n+1)-digit
 * number by decomposing t into digits 9 down to 2 and padding with leading 1s.
 *
 * Time Complexity: O(n * 9) where n is the length of num; each position scans at most
 * 9 digit choices and fills remaining slots in O(n) with constant digit checks.
 * Space Complexity: O(n) for the remainder array and output string.
 *
 * Runtime: 36 ms | Memory: 46.9 MB
 */

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0) {
                temp /= i;
            }
        }
        if (temp > 1) {
            return "-1";
        }
        int n = num.length();
        vector<long long> rem(n + 1);
        rem[0] = t;
        int pos = n - 1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }
        if (rem[n] == 1) {
            return num;
        }

        for (int i = pos; i >= 0; i--) {
            while (++num[i] <= '9') {
                long long tNow = rem[i] / gcd(rem[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tNow % k) {
                        k--;
                    }
                    tNow /= k;
                    num[j] = '0' + k;
                }
                if (tNow == 1) {
                    return num;
                }
            }
        }

        string ans;
        for (int i = 9; i > 1; i--) {
            while (t % i == 0) {
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
        ranges::reverse(ans);
        return ans;
    }
};
