/*
 * 1344. Angle Between Hands of a Clock - Medium
 * https://leetcode.com/problems/angle-between-hands-of-a-clock/
 *
 * Approach: Mathematical Formula
 * The hour hand position is expressed as (hour + minutes/60.0) in 12-hour units.
 * The difference between the minute and hour hand positions is proportional to 11/12 of the hour value (mod 12), since the minute hand moves 12x faster than the hour hand, giving a relative speed factor of 11.
 * The minimum angle is obtained by taking the smaller of the two possible arcs, scaled by 30 degrees per hour unit.
 *
 * Time Complexity: O(1) - only constant-time arithmetic operations performed.
 * Space Complexity: O(1) - no additional data structures used.
 *
 * Runtime: 0 ms
 * Memory: 8.1 MB
 */

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = hour + minutes / 60.0;
        double diff = fmod(11.0 * x, 12.0);
        return min(diff, 12.0 - diff) * 30.0;
    }
};
