/*
 * Problem #150: Evaluate Reverse Polish Notation (Medium)
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *
 * Approach: Stack-based evaluation using an unordered_set for O(1) operator lookup.
 * Iterate through tokens; push operands onto the stack, and when an operator is
 * encountered, pop the top two operands, apply the operator, and push the result back.
 * The final answer remains as the sole element on the stack after all tokens are processed.
 *
 * Time Complexity: O(n) - single pass through all n tokens with O(1) stack and set operations.
 * Space Complexity: O(n) - stack can hold at most n/2 + 1 operands in the worst case.
 *
 * Runtime: 8 ms
 * Memory: 17.1 MB
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"*" , "-", "+" , "/"};

        for(string s : tokens){
            if(operators.find(s) != operators.end()){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res = 0;
                if(s == "/") res = a/b;
                else if(s == "*") res = a*b;
                else if(s == "-") res = a-b;
                else if(s == "+") res = a+b;
                st.push(res);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};


