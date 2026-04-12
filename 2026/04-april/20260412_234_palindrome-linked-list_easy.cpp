/*
 * Problem 234: Palindrome Linked List (Easy)
 * https://leetcode.com/problems/palindrome-linked-list/
 *
 * Approach: Linear Traversal with Vector Storage
 * Traverse the entire linked list once, storing all node values into a vector.
 * Then use two-pointer comparison from both ends toward the center to check if the sequence is a palindrome.
 * If any mirrored pair of values differs, return false; otherwise return true.
 *
 * Time Complexity: O(n) - single pass to collect values, single pass (n/2) to compare ends.
 * Space Complexity: O(n) - vector stores all n node values from the linked list.
 *
 * Runtime: 5 ms
 * Memory: 132 MB
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
    bool isPalindrome(ListNode* head) {
        vector<int> stack;
        ListNode* tmp = head;
        while(tmp) {
            stack.push_back(tmp->val);
            tmp = tmp -> next;
        }
        for(int i=0; i<stack.size()/2; i++){
            if(stack[i] != stack[stack.size()-1-i]) return false;
        }
        return true;
    }
};
