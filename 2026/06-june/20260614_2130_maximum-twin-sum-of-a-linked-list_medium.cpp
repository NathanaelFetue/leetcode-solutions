/*
 * 2130. Maximum Twin Sum of a Linked List - Medium
 * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 *
 * Approach: Reverse First Half In-Place + Two Pointer Traversal
 * Use slow/fast pointers to find the midpoint while simultaneously reversing the first half
 * of the list in-place using pointer swaps. Then traverse the reversed first half and the
 * second half together, computing twin sums and tracking the maximum.
 *
 * Time Complexity: O(n) - single pass to reverse first half, single pass to compute twin sums.
 * Space Complexity: O(1) - reversal is done in-place using pointer manipulation, no extra data structures.
 *
 * Runtime: 4 ms
 * Memory: 120.5 MB
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            swap(slow->next, prev);
            swap(prev, slow);
        }

        int res = 0;
        while (slow) {
            res = max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return res;
    }
};
