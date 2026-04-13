/*
 * Problem #707: Design Linked List (Medium)
 * https://leetcode.com/problems/design-linked-list/
 *
 * Approach: Implements a singly linked list with explicit head and tail pointers
 * and a size counter. Each operation (get, add, delete) traverses the list from
 * the head up to the target index, with special-cased O(1) head and tail updates.
 *
 * Time Complexity:
 *   - get: O(n) - linear traversal to index
 *   - addAtHead: O(1) - direct pointer update
 *   - addAtTail: O(1) - tail pointer maintained
 *   - addAtIndex: O(n) - traversal to insertion point
 *   - deleteAtIndex: O(n) - traversal to deletion point
 *
 * Space Complexity: O(n) - one Node allocated per stored element
 *
 * Runtime: 11 ms | Memory: 25.8 MB
 */

class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() :  head(nullptr) , tail(nullptr) , size(0) {}
    
    int get(int index) {
        int i = 0;
        if (index < i || index > size-1) return -1;
        Node* tmp = head;
        while( i<index){
            tmp = tmp -> next;
            i+=1;
        }
        return tmp->val;

    }
    
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        tmp -> next = head;
        head = tmp;
        if(size == 0) tail = tmp;
        size++;
    }
    void addAtTail(int val) {
        Node* tmp = new Node(val);
        if (size == 0) { head = tmp; tail = tmp; size++; return; }
        tail->next = tmp;
        tail = tmp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <0 || index > size) return ;
        Node* tmp = new Node(val);
        int i = 0;
        Node *prev , *curr= head;
        if (index==0) {addAtHead(val); return;}
        if (index==size) {addAtTail(val); return;}
        else{
            while(i <index){
                prev = curr;
                curr = curr -> next;
                i++;
            }
            prev -> next = tmp;
            tmp-> next = curr;
        }
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) { 
            Node* tmp = head;
            head = head->next; 
            delete tmp;
            if (size == 1) tail = nullptr;
            size--; 
            return; 
        }
        int i = 0;
        Node *prev, *curr = head;
        while (i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        if (index == size - 1) tail = prev;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
