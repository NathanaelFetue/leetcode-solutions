/*
 * Problem #707 - Design Linked List
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/design-linked-list/
 *
 * Approach/Algorithm:
 * Implements a singly linked list with head and tail pointers plus a size counter.
 * Each operation leverages the tail pointer to achieve O(1) addAtTail, while get,
 * addAtIndex, and deleteAtIndex traverse the list iteratively to locate the target node.
 *
 * Time Complexity:
 * - get(index): O(n) - linear traversal to index
 * - addAtHead(val): O(1) - direct head pointer update
 * - addAtTail(val): O(1) - direct tail pointer update
 * - addAtIndex(index, val): O(n) - traversal to insertion point
 * - deleteAtIndex(index): O(n) - traversal to deletion point
 *
 * Space Complexity: O(n) - one Node allocated per stored element
 *
 * Runtime: 6 ms | Memory: 25.9 MB
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
        if (index == size - 1) tail = prev;  // mise à jour tail si dernier noeud
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
