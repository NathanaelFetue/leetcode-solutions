/*
 * Problem #155 - Min Stack (Medium)
 * LeetCode: https://leetcode.com/problems/min-stack/
 *
 * Approach: Two-Vector Stack with Min-Index Tracking
 * Uses a primary vector `st` to store all values and an auxiliary vector `minIdx`
 * that tracks indices of elements which are the current minimum at the time of push.
 * The minIdx stack only grows when a new value is less than or equal to the current
 * minimum, and shrinks when the element at the top of minIdx is popped from the main stack.
 * This avoids storing redundant min values and instead references back into `st`.
 *
 * Time Complexity: O(1) for all operations (push, pop, top, getMin)
 *   - Each operation does at most constant work on the back of a vector.
 *
 * Space Complexity: O(n) where n is the number of elements pushed
 *   - `st` holds all n elements; `minIdx` holds at most n indices.
 *
 * Runtime : 53 ms
 * Memory  : 152.6 MB
 */

class MinStack {
    vector<int> st;
    vector<int> minIdx;

public:
    MinStack() {}

    void push(int val) {
        st.push_back(val);
        if (minIdx.empty() || val <= st[minIdx.back()])
            minIdx.push_back(st.size() - 1);
    }

    void pop() {
        if (st.size() - 1 == minIdx.back())
            minIdx.pop_back();
        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return st[minIdx.back()];
    }
};
