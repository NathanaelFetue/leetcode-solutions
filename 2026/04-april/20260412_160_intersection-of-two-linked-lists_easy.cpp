/*
 * Problem 160: Intersection of Two Linked Lists (Easy)
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Approach: Hash Set Membership Check
 * Traverse list A and store all node pointers in an unordered_set.
 * Then traverse list B, checking each node against the set; the first
 * node found in the set is the intersection point, or nullptr if none exists.
 *
 * Time Complexity: O(m + n) — where m and n are the lengths of list A and
 * list B respectively; each list is traversed at most once.
 *
 * Space Complexity: O(m) — the hash set stores all node pointers from list A.
 *
 * Runtime: 79 ms
 * Memory: 28.8 MB
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
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        unordered_set <ListNode*> st;
        int val;
        while(tmp1) {
            st.insert(tmp1);
            tmp1 = tmp1->next;
        }
        while(tmp2) {
            if(st.contains(tmp2)) return tmp2;
            tmp2 = tmp2->next;
        }
        return nullptr;
    }
};
