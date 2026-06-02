/*
 * Problem #3633: Earliest Finish Time for Land and Water Rides I (Easy)
 * URL: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
 *
 * Approach: Brute-force enumeration of all pairs of one land ride and one water ride.
 * For each pair, we consider both orderings: land first then water, and water first then land.
 * The start time of the second ride is the max of its earliest available time and when the first ride finishes, and we track the minimum overall finish time.
 *
 * Time Complexity: O(n * m) where n = number of land rides and m = number of water rides.
 * We iterate over every combination of one land ride and one water ride.
 *
 * Space Complexity: O(1) — only a constant number of variables are used beyond the input.
 *
 * Runtime: 7 ms | Memory: 91.8 MB
 */

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                ans = min(ans, startWater + waterDuration[j]);

                int finishWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(finishWater, landStartTime[i]);
                ans = min(ans, startLand + landDuration[i]);
            }
        }
        return ans;
    }
};
