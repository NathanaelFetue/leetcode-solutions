/*
 * Problem #83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Use a set to track all values seen so far while traversing the list
 * with a dummy head node. For each node, if its value already exists in the set,
 * skip it by relinking pointers; otherwise, add it to the set and advance.
 *
 * Time Complexity: O(n log n) - each of the n nodes is processed once, and each
 * set insertion/lookup takes O(log n) due to the balanced BST backing std::set.
 *
 * Space Complexity: O(n) - the set stores at most n unique values from the list.
 *
 * Note: Since the list is already sorted, a simple O(n) in-place comparison of
 * adjacent nodes would suffice, but this set-based approach also handles unsorted
 * duplicates.
 *
 * Runtime: 0 ms | Memory: 16.9 MB
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
    ListNode* deleteDuplicates(ListNode* head) {
        set <double> s = {};
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while(curr -> next) {
            if (s.contains(curr->next -> val)) {
                curr -> next = curr -> next -> next ;
            } else {
                s.insert(curr ->next-> val);
                curr = curr -> next;
            }
        } 
        return dummy.next;
    }
};
