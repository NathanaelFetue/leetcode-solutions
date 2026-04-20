/*
 * Problem #61 - Rotate List (Medium)
 * LeetCode URL: https://leetcode.com/problems/rotate-list/
 *
 * Approach: Linked List Traversal with Reconnection
 * First, traverse the list to compute its length and reach the tail node.
 * Using the effective rotation count (k % length), find the new tail at position
 * (length - k % length - 1), split the list there, and reconnect the tail to
 * the original head, returning the new head of the rotated list.
 *
 * Time Complexity: O(n) - Two passes at most over the list; one to find length
 * and tail, one to find the split point.
 * Space Complexity: O(1) - Only a constant number of pointer variables are used;
 * no additional data structures are allocated.
 *
 * Runtime: 0 ms
 * Memory: 16.4 MB
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode *tmp1 = head, *tmp2 = head;
        int taille = 1;
        while (tmp2->next) { tmp2 = tmp2->next; taille++; }

        int pos = taille - k % taille - 1;
        if (k % taille == 0) return head;
        tmp1 = head;
        for (int i = 0; i < pos; i++) tmp1 = tmp1->next;

        ListNode* rot = tmp1->next;
        tmp1->next = nullptr;
        tmp2->next = head;
        return rot;
    }
};
