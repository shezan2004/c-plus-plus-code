#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int cal(int v1, int v2, char op) {
    if (op == '^') {
        return pow(v1, v2);
    }
    if (op == '/') {
        return v1 / v2;
    }
    if (op == '*') {
        return v1 * v2;
    }
    if (op == '+') {
        return v1 + v2;
    }
    return v1 - v2;
}

int evaluate(string &str) {
    stack<int> st;
    // Start from the end of the string and move towards the start
    for (int i = str.size() - 1; i >= 0; i--) {
        char ch = str[i];
        if (isdigit(ch)) {
            st.push(ch - '0');  // Convert character to integer and push onto the stack
        } else {
            // Operator found, pop two elements from stack
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            // Apply the operator and push the result back onto the stack
            int result = cal(v1, v2, ch);
            st.push(result);
        }
    }
    // The final result will be the top element of the stack
    return st.top();
}

int main() {
    string str = "-9+*132";
    cout << evaluate(str);
    return 0;
}

