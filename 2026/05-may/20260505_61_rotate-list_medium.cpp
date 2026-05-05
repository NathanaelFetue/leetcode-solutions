/*
 * Problem #61 - Rotate List
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/rotate-list/
 *
 * Approach: First traverse the list to compute its length and obtain a pointer to the tail node.
 * Then calculate the effective rotation position as (length - k % length - 1), which identifies
 * the new tail node. Split the list at that point, reconnect the tail to the original head,
 * and return the new head (the node after the split point).
 *
 * Time Complexity: O(n) - two passes over the list: one to find the length and tail,
 * one to find the split point.
 * Space Complexity: O(1) - only a constant number of pointers are used, no extra allocation.
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
