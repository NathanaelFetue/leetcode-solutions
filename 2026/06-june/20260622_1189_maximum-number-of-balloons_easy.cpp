/*
 * Problem 1189: Maximum Number of Balloons (Easy)
 * https://leetcode.com/problems/maximum-number-of-balloons/
 *
 * Approach: Frequency Count with Minimum Constraint
 * Count the frequency of each character in the input string using a hash map.
 * Since the word 'balloon' requires 1 'b', 1 'a', 2 'l', 2 'o', and 1 'n', divide
 * the counts of 'l' and 'o' by 2, then return the minimum across all required characters.
 *
 * Time Complexity: O(n) - single pass through the string to build frequency map,
 * where n is the length of the input string.
 *
 * Space Complexity: O(1) - the hash map stores at most 26 distinct characters,
 * which is a constant upper bound regardless of input size.
 *
 * Runtime: 0 ms | Memory: 9.2 MB
 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int> mp;
        for(char c : text){
            mp[c]++;
        }
        int val = 0;
        val = min({mp['b'] ,mp['a'], mp['l']/2, mp['o']/2,mp['n']});

        return val;
    }
};
