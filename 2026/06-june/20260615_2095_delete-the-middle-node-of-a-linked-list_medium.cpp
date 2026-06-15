/*
 * Problem #2095: Delete the Middle Node of a Linked List (Medium)
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 *
 * Approach: Fast and Slow Pointer (Floyd's Tortoise and Hare)
 * Use two pointers where fast moves two steps and slow moves one step per iteration.
 * When fast reaches the end, slow points to the middle node; track the previous node to unlink it.
 *
 * Time Complexity: O(n) - single pass through the linked list to locate the middle node.
 * Space Complexity: O(1) - only a constant number of pointers are used regardless of list size.
 *
 * Runtime: 4 ms
 * Memory: 312.1 MB
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};
