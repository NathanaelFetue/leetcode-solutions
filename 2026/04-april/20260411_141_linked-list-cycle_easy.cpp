/*
 * Problem #141: Linked List Cycle (Easy)
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Approach: Floyd's Cycle Detection Algorithm (Tortoise and Hare).
 * Two pointers, slow and fast, start at the head. Slow advances one node per
 * iteration while fast advances two nodes. If a cycle exists, fast will eventually
 * catch up to slow and they will point to the same node.
 *
 * Time Complexity: O(n) - In the worst case, the fast pointer traverses the
 * entire list once before either detecting a cycle or reaching the end.
 *
 * Space Complexity: O(1) - Only two pointers are used regardless of list size,
 * no additional data structures are needed.
 *
 * Runtime: 12 ms | Memory: 11.7 MB
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
