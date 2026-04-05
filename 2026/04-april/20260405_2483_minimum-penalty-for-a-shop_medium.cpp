/*
 * Problem #2483 - Minimum Penalty for a Shop
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-penalty-for-a-shop/
 *
 * Approach: Prefix Sum / Greedy Single Pass
 * First count the total number of 'Y' (customer) days. Then iterate through each
 * possible closing hour, tracking seen 'N's (penalty for being open with no customers)
 * and remaining 'Y's after current position (penalty for being closed during customer days).
 * At each index, penalty = seenN + (totalY - seenY). Track the minimum penalty and its index.
 *
 * Time Complexity: O(n) - one pass to count total Y's, one pass to find minimum penalty.
 * Space Complexity: O(1) - only a constant number of integer variables used.
 *
 * Runtime: 8 ms
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
