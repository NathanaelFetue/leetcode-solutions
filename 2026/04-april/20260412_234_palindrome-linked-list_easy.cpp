/*
 * Problem 234: Palindrome Linked List (Easy)
 * https://leetcode.com/problems/palindrome-linked-list/
 *
 * Approach: Linear scan with vector storage.
 * Traverse the linked list once, storing all node values into a vector.
 * Then use two-pointer comparison from both ends toward the center to check for palindrome symmetry.
 *
 * Time Complexity: O(n) - single pass to collect values plus O(n/2) for comparison, overall O(n).
 * Space Complexity: O(n) - vector stores all n node values.
 *
 * Runtime: 4 ms
 * Memory: 132.1 MB
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
