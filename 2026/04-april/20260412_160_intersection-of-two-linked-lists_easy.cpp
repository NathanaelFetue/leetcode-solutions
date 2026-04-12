/*
 * Problem 160: Intersection of Two Linked Lists (Easy)
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Two-pointer technique with list switching.
 * Two pointers traverse both lists simultaneously; when one pointer reaches the end
 * of its list it is redirected to the head of the other list. This equalizes the
 * total distance traveled so both pointers meet at the intersection node (or null
 * if no intersection exists), since they will have traversed len(A)+len(B) steps.
 *
 * Time Complexity : O(m + n) - each pointer traverses at most m + n nodes,
 *                   where m and n are the lengths of the two lists.
 * Space Complexity: O(1) - only two pointer variables are used regardless of input size.
 *
 * Runtime : 60 ms
 * Memory  : 23.8 MB
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
