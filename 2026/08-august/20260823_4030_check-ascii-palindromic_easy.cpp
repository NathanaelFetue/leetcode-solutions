/*
 * Problem 4030: Check ASCII Palindromic
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-ascii-palindromic/
 *
 * Approach:
 * The key insight is that ASCII palindromic validation must be performed on the continuous 8-bit binary representation of the entire string rather than the character literals themselves. By flattening the string into a monolithic bitstream where each character is mapped to its 8-bit binary equivalent via std::bitset, we establish a uniform sequence of '0' and '1' characters. We then apply a two-pointer convergent search from both ends of the bitstream to verify symmetry. This reduction guarantees that any asymmetric bit pattern is immediately caught, ensuring correctness while avoiding complex bit-manipulation offsets.
 *
 * Time Complexity: O(N) — where N is the length of the input string. Converting each character to its 8-bit representation takes O(1) auxiliary operations, and the subsequent two-pointer traversal scales linearly with the size of the bitstream (8 * N).
 * Space Complexity: O(N) — to store the flattened binary string representation, which dynamically allocates 8 * N bytes of memory.
 *
 * Runtime: 4 ms | Memory: 9.3 MB
 */

class Solution {
public:
    bool isPalindromic(string s) {
        string bin = "";
        for(char c : s) bin += bitset<8>(c).to_string();
        int l=0, r=bin.size() -1;
        while(l < r){
            if(bin[l] != bin[r]) return false;
            r--; l++;
        }
        return true;
    }
};
