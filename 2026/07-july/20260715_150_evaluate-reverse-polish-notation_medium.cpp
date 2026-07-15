/*
 * Problem #150: Evaluate Reverse Polish Notation (Medium)
 * URL: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 *
 * Approach: Stack-based evaluation of Reverse Polish Notation (postfix expression).
 * Iterate through each token; push operands onto the stack, and when an operator
 * is encountered, pop the top two operands, apply the operator, and push the result back.
 * The final answer remains as the sole element on the stack after all tokens are processed.
 *
 * Time Complexity: O(n) - each token is visited exactly once, and all stack/set
 * operations (push, pop, unordered_set lookup) run in O(1) amortized time.
 *
 * Space Complexity: O(n) - in the worst case (all operands before operators),
 * the stack holds up to n/2 elements, giving O(n) auxiliary space.
 *
 * Runtime: 5 ms
 * Memory: 17.2 MB
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


