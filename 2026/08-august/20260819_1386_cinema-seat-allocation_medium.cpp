/*
 * Problem 1386: Cinema Seat Allocation
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/cinema-seat-allocation/
 *
 * Approach:
 * The key insight is that columns 1 and 10 are completely irrelevant, leaving only columns 2 through 9 as candidates for placing 4-person families. We compress these 8 active columns of each row into an 8-bit integer mask, where a set bit represents a reserved seat. By using a hash map to record reservations, we can bypass the massive row count (up to 10^9) and focus only on the "dirty" rows with reservations, assuming all clean rows automatically hold 2 families. Finally, we use bitwise OR operations with predefined masks representing the left, middle, and right seating blocks to check if at least one valid family configuration fits in each dirty row.
 *
 * Time Complexity: O(R) — where R is the number of reserved seats, driven by a single pass to construct the hash map of dirty rows and a subsequent pass to evaluate the seating configurations for each of those rows.
 * Space Complexity: O(R) — where R is the number of reserved seats, representing the maximum memory needed by the hash map to store the bitmasks of unique dirty rows.
 *
 * Runtime: 19 ms | Memory: 58.9 MB
 */

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;

        unordered_map<int, int> occupied;
        for (const vector<int>& seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;
        for (auto& [row, bitmask] : occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
                ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};
