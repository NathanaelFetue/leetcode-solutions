/*
 * Problem #2490 - Circular Sentence
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/circular-sentence/
 *
 * Approach/Algorithm:
 * Iterate through the sentence checking every space character to verify that the
 * last character of the preceding word matches the first character of the next word.
 * Additionally, verify that the last character of the entire sentence matches the
 * first character, completing the circular condition.
 *
 * Time Complexity: O(n) - single pass through all characters in the sentence.
 * Space Complexity: O(1) - only a constant number of variables used, no extra storage.
 *
 * Runtime: 0 ms
 * Memory: 9.3 MB
 */

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i=0; i<sentence.size();i++){
            if (i!=0) {
                if(sentence[i] == ' '){
                    char prev = sentence[i-1];
                    char next = sentence[i+1];
                    if(prev != next) return false;
                }
            }
            if(i==sentence.size()-1) if(sentence[0] != sentence[i]) return false;
        }
        return true;
    }
};
