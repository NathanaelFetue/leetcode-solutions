/*
 * Problem 160: Intersection of Two Linked Lists (Easy)
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Two-pointer traversal with list switching.
 * Two pointers traverse both lists simultaneously. When a pointer reaches the end of its list,
 * it is redirected to the head of the other list. This equalizes the total distance traveled
 * by both pointers, guaranteeing they meet at the intersection node (or both reach NULL if no intersection exists).
 *
 * Time Complexity: O(m + n) - each pointer traverses at most the combined length of both lists.
 * Space Complexity: O(1) - only two pointers used, no extra data structures.
 *
 * Runtime: 1658 ms
 * Memory: 23.9 MB
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
            tmp1 = tmp1 ? tmp1->next : headA;
            tmp2 = tmp2 ? tmp2->next : headB;
        }
        return tmp1;
    }
};
