/*
 * Problem #242 - Valid Anagram (Easy)
 * LeetCode: https://leetcode.com/problems/valid-anagram/
 *
 * Approach: Hash Map Frequency Count
 * First, check if both strings have equal length; if not, they cannot be anagrams.
 * Build a frequency map of characters from string s, then iterate through string t,
 * decrementing counts for each matched character. Return false if a character is missing
 * or its count has already reached zero, indicating a mismatch in frequency.
 *
 * Time Complexity : O(n) - where n is the length of the strings; two linear passes are made.
 * Space Complexity: O(1) - the hash map stores at most 26 unique lowercase English letters,
 *                          so the space is bounded by a constant.
 *
 * Runtime : 0 ms
 * Memory  : 9.9 MB
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map <char , int> mp;
        for(auto c : s){
            mp[c]++;
        }
        for(auto c : t) {
            if(!mp.contains(c)) return false;
            else{
                if(mp[c] >0) mp[c] --;
                else return false;
            }
        }
        return true;
    }
};

