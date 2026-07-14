/*
 * Problem #155 - Min Stack (Medium)
 * https://leetcode.com/problems/min-stack/
 *
 * Approach: Two-vector approach where one vector acts as the main stack and a second
 * vector (minIdx) tracks indices of minimum elements. On push, a new index is added
 * to minIdx only when the new value is less than or equal to the current minimum,
 * ensuring getMin always resolves via the last recorded minimum index.
 *
 * Time Complexity: O(1) for all operations (push, pop, top, getMin) - each operation
 * performs at most a constant number of vector accesses or comparisons.
 *
 * Space Complexity: O(n) where n is the number of elements pushed; in the worst case
 * (monotonically decreasing inputs) minIdx grows proportionally with st.
 *
 * Runtime : 59 ms
 * Memory  : 152.4 MB
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
