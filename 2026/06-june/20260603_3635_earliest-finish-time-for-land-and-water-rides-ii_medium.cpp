/*
 * Problem #3635: Earliest Finish Time for Land and Water Rides II (Medium)
 * https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
 *
 * Approach: Greedy two-pass simulation tried in both orders (land->water and water->land).
 * For the first ride type, pick the option that finishes earliest (min of start+duration).
 * For the second ride type, each option starts at max(its start time, first ride finish), and we again pick the minimum finish time. Return the best of both orderings.
 *
 * Time Complexity: O(n + m) where n = number of land rides and m = number of water rides.
 * Both solve() calls each do two linear scans over the two ride arrays.
 *
 * Space Complexity: O(1) extra space; only a constant number of variables are used beyond the input arrays.
 *
 * Runtime: 2 ms
 * Memory: 238.1 MB
 */

class Solution {
    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
              vector<int>& duration2) {
        int finish1 = INT_MAX;
        for (int i = 0; i < start1.size(); i++) {
            finish1 = min(finish1, start1[i] + duration1[i]);
        }

        int finish2 = INT_MAX;
        for (int i = 0; i < start2.size(); i++) {
            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
        }
        return finish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int land_water =
            solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int water_land =
            solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(land_water, water_land);
    }
};
