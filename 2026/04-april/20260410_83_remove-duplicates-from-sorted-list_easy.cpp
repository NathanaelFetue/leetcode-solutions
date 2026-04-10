/*
 * Problem 83: Remove Duplicates from Sorted List (Easy)
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 *
 * Approach: Hash Set with Dummy Node Traversal
 * A dummy node is prepended to simplify edge-case handling at the head.
 * We traverse the list, tracking seen values in a set; if the next node's
 * value has already been seen, we skip it by relinking pointers, otherwise
 * we record the value and advance the current pointer.
 *
 * Time Complexity: O(n) — each node is visited exactly once during traversal.
 * Space Complexity: O(n) — the set stores at most n distinct node values.
 *
 * Runtime: 0 ms
 * Memory: 16.9 MB
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;
        while (curr->next) {
            if (s.contains(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                s.insert(curr->next->val);
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
