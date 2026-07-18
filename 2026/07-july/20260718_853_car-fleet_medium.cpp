/*
 * Problem #853 - Car Fleet (Medium)
 * URL: https://leetcode.com/problems/car-fleet/
 *
 * Approach: Sort cars by starting position in descending order (closest to target first).
 * Compute the time each car takes to reach the target. Use a stack to track fleet counts:
 * if a car takes longer than the car ahead of it, it forms a new fleet; otherwise it merges.
 *
 * Time Complexity: O(n log n) — dominated by the sorting step over n cars.
 * Space Complexity: O(n) — for the cars array and the stack storing at most n times.
 *
 * Runtime : 34 ms
 * Memory  : 105.9 MB
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        stack<double> st;
        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            if (st.empty() || time > st.top())
                st.push(time);
        }
        return st.size();
    }
};
