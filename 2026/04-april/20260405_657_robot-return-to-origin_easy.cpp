/*
 * Problem #657 - Robot Return to Origin
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/robot-return-to-origin/
 *
 * Approach/Algorithm:
 * Use two integer counters to track the robot's net displacement along the vertical (i)
 * and horizontal (j) axes. Iterate through each move character, incrementing or decrementing
 * the appropriate counter, then check if both counters return to zero at the end.
 *
 * Time Complexity: O(n) - where n is the length of the moves string, as we perform
 * a single linear pass through all characters.
 *
 * Space Complexity: O(1) - only two integer variables are used regardless of input size.
 *
 * Runtime: 0 ms
 * Memory: 10.5 MB
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int i =0, j=0;
        for (char m : moves) {
            if (m == 'U') {
                i+=1;
            } else if (m== 'D') {
                i--;
            } else if (m== 'R'){
                j++;
            } else j--;
        }
        return ((i==0) && (j==0));
    }
};
