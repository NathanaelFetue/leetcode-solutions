/*
 * Problem #2483 - Minimum Penalty for a Shop
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-penalty-for-a-shop/
 *
 * Approach: Prefix Sum / Greedy Single Pass
 * First count total 'Y's in the string (representing customers who arrive). Then iterate
 * through each hour, tracking seen 'N's (penalty for being open with no customer) and
 * remaining 'Y's after current position (penalty for being closed when customers arrive).
 * At each position the total penalty is seenN + (totalY - seenY), and we track the minimum.
 *
 * Time Complexity: O(n) - two linear passes over the customers string (one count, one scan).
 * Space Complexity: O(1) - only a fixed number of integer variables are used.
 *
 * Runtime: 7 ms
 * Memory: 13.5 MB
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
