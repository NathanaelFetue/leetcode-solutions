/*
 * Problem 160: Intersection of Two Linked Lists
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Two-Pointer / Pointer Redirection
 * Two pointers traverse both lists simultaneously. When a pointer reaches the end of its list,
 * it is redirected to the head of the other list. By the time both pointers have traversed
 * a combined distance of lenA + lenB, they will either meet at the intersection node or both
 * become null (no intersection), guaranteeing convergence without needing to compute lengths.
 *
 * Time Complexity: O(m + n) — each pointer traverses at most m + n nodes total,
 * where m and n are the lengths of the two linked lists.
 * Space Complexity: O(1) — only two pointer variables are used regardless of input size.
 *
 * Runtime: 61 ms
 * Memory: 24 MB
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA, *tmp2 = headB;
        while (tmp1 != tmp2) {
            tmp1 = tmp1 ? tmp1->next : headB;
            tmp2 = tmp2 ? tmp2->next : headA;
        }
        return tmp1;
    }
};
