/*
 * Problem #1288 - Remove Covered Intervals (Medium)
 * https://leetcode.com/problems/remove-covered-intervals/
 *
 * Approach: Sort intervals by start time ascending; for equal start times, sort by end time descending.
 * Iterate with two pointers: if the current interval's end covers the next interval's end, the next is covered and decremented from the count.
 * Otherwise, advance the left pointer to the right pointer's position, effectively moving to a new potential covering interval.
 *
 * Time Complexity: O(n log n) - dominated by the sorting step; the two-pointer scan is O(n).
 * Space Complexity: O(1) - sorting is in-place and only a constant number of extra variables are used.
 *
 * Runtime: 2 ms
 * Memory: 15.1 MB
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        if (intervals.size() == 1) return intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int  i = 0 , j=1 , nbInt = intervals.size();
        while (i < intervals.size() && j < intervals.size()) {
            if (intervals[i][1] >= intervals[j][1]) {
                nbInt--;
                j++;
            } else {
                i = j;
                j++;
            }
        }

        return nbInt;
    }
};
