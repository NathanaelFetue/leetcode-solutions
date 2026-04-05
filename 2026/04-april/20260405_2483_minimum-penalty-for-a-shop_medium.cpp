/*
 * Problem #2483 - Minimum Penalty for a Shop
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-penalty-for-a-shop/
 *
 * Approach: Prefix Sum / Greedy Single Pass
 * First count total 'Y's in the string to establish the baseline penalty (closing at hour 0).
 * Then iterate through each hour, tracking seen 'N's (penalty for being open) and remaining 'Y's
 * (penalty for being closed), updating the best closing time whenever a lower penalty is found.
 *
 * Time Complexity: O(n) - two linear passes over the string (one count, one iteration).
 * Space Complexity: O(1) - only a fixed number of integer variables are used regardless of input size.
 *
 * Runtime: 12 ms
 * Memory: 13.4 MB
 */

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = count(customers.begin(), customers.end() , 'Y');
        int minPen = totalY , best=0;
        int seenY =0, seenN =0;
        int pen =0;

        for (int i=0; i< n; i++){
            if (customers[i] == 'Y') seenY++;
            else seenN++;
            pen = seenN + ( totalY- seenY);
            if (pen< minPen) {
                minPen = pen;
                best = i+1;
            }
        }
        return best;
    }
};
