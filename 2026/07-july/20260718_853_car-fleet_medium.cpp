/*
 * Problem #853: Car Fleet (Medium)
 * URL: https://leetcode.com/problems/car-fleet/
 *
 * Approach: Greedy + Monotonic Stack
 * First, pair each car's position with its speed and sort all cars in descending
 * order by position (closest to target first). For each car, compute the time it
 * would take to reach the target. Use a stack to track distinct fleets: if a car's
 * time is greater than the top of the stack, it cannot catch the car ahead and
 * forms a new fleet; otherwise it merges into the leading fleet and is discarded.
 *
 * Time Complexity: O(n log n) — dominated by the sorting step over n cars.
 * Space Complexity: O(n) — for the auxiliary cars array and the stack, each
 * holding at most n elements.
 *
 * Runtime: 46 ms
 * Memory: 105.8 MB
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
