/*
 * Problem 160: Intersection of Two Linked Lists (Easy)
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Two-pointer traversal with list switching.
 * Two pointers start at the heads of each list and advance one node at a time.
 * When a pointer reaches the end of its list, it is redirected to the head of the other list.
 * This ensures both pointers travel the same total distance (lenA + lenB) before meeting
 * at the intersection node, or both become null if no intersection exists.
 *
 * Time Complexity: O(m + n) - each pointer traverses at most both lists once,
 * where m and n are the lengths of the two linked lists.
 * Space Complexity: O(1) - only two pointers are used regardless of input size.
 *
 * Runtime: 1692 ms
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
