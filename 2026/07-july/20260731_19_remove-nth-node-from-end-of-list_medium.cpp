/*
 * Problem #19: Remove Nth Node From End of List (Medium)
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Approach: Two-pointer (slow and fast) technique with a dummy head node.
 * The fast pointer is advanced n+1 steps ahead of slow, then both move together
 * until fast reaches null — slow then points to the node just before the target.
 * The target node is removed by relinking slow->next to slow->next->next.
 *
 * Time Complexity: O(L) — single pass through the list where L is the list length.
 * Space Complexity: O(1) — only two extra pointers used, no additional data structures.
 *
 * Runtime: 0 ms
 * Memory: 15 MB
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i <= n; i++)
            fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};
