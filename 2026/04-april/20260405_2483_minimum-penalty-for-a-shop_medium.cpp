/*
 * Problem #2483: Minimum Penalty for a Shop
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/minimum-penalty-for-a-shop/
 *
 * Approach: Prefix scan with running penalty calculation.
 * First count total 'Y' customers. Then iterate through each hour, tracking seen 'Y's and 'N's.
 * At each closing time i+1, penalty = seenN (no-shows before close) + (totalY - seenY) (missed customers after close).
 * Initial penalty (close at hour 0) equals totalY. Track minimum penalty and its index.
 *
 * Time Complexity: O(n) - single pass through the string after an O(n) count.
 * Space Complexity: O(1) - only a fixed number of integer variables used.
 *
 * Runtime: 9 ms
 * Memory: 13.2 MB
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
