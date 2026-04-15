/*
 * Problem #1652 - Defuse the Bomb
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/defuse-the-bomb/
 *
 * Approach/Algorithm:
 * For each element in the circular array, compute the sum of the next k elements (if k > 0)
 * or the previous |k| elements (if k < 0), replacing each element with that sum.
 * Modular arithmetic is used to wrap around the circular array boundaries in both directions.
 * If k == 0, all elements are replaced with 0 and returned immediately.
 *
 * Time Complexity: O(n * |k|) - for each of the n elements, we iterate over |k| neighbors.
 * Space Complexity: O(n) - result array of size n is allocated to store the output.
 *
 * Runtime: 0 ms
 * Memory: 11.6 MB
 */

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> res(n,0);
        if (k==0) return res;
        for (int i =0; i<n ; i++) {
            int sum =0;
            for (int j = 0; j< abs(k);j++) {
                if(k>0) sum += code[(i+j+1)%n];
                else sum += code[(i-j -1 +n) %n];
            }
            res[i] = sum;
        }
        return res;
    }
};
