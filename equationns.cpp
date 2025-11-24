#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")
using namespace std;

#define firstio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// Author_Name: Tipto_Ghosh
// Last Updated: 14-08-2024


typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;
const int N = 1e7 + 10;
const int mod = 1e9 + 7;
const double pi = 3.14159265358979323846;
const double inf_double = numeric_limits<double>::infinity();
const int inf_int = numeric_limits<int>::max();
#define all(x) (x).begin(), (x).end()


//------------------Solve Here----------------------------------

// Infix to postfix:
/*

step-1: Interate through the string by maintaining index[using a Loop]
step-2: If it's an Operand then add it in the ans
step-3: If it's an Operator and stack is empty then store it in the stack
step-4: If it's an Operator and stack is not empty then There can be 2 Case:
    
    case-1: if current operator priority is higher than top then store it into the stack and move on
    case-2: if current operator priority is lower than top then remove top and add in the ans until current operator priority is high
step-4: if it's an opening bracket then just store it in the stack and move forward
step-5: If it's an closing bracket remove all top from the stack and add in the ans untill you got opening brackets
*/

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
       return true;
    }
  return false;  
}
bool isOperand(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return true;
    }
  return false;  
}
int precedence(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 2;
    else return -1; 
}

string infixToPostfix(string s) {
    string ans = "";
    stack<char> st;
    int n = s.length();
    for(int i = 0; i < n; i++) {

       // If it's an Operand store it into the ans
       if(isOperand(s[i])) {
          ans.push_back(s[i]);
       }
       else if(s[i] == '(') {
          st.push(s[i]);
       }
       else if(s[i] == ')') {
          // remove all untill we got opening
          while(!st.empty() && st.top() != '(') {
            ans.push_back(st.top());
            st.pop();
          }
          // now remove the opening also
          st.pop();
       }    
        else if(isOperator(s[i])) {
            // remove all operand utill top has greater than equal precendence
            while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
               ans.push_back(st.top());
               st.pop();
            }    
           // now push the current operator in the stack
           st.push(s[i]); 
        }     
    }

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
  return ans;  
}

//  Infix to Prefix
/*
  Step-1: Reverse the given string[Opening bracket will be closing and closing will be opening]
  step-2: Convert Infix to postfix
  Step-3: Reverse the ans
*/

string infixToPrefix(string s) {
    // reverse the string and convert opening to closing and vice versa
    reverse(all(s));
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            s[i] = ')';
        }
        else if(s[i] == ')') {
            s[i] = '(';
        }
    }

    // step-02: get postfix
    string postfix = infixToPostfix(s);
    reverse(all(postfix));
  return postfix;  
}

// Postfix to Infix
/*
   1. If operand push into the stack
   2. If operator then pick 2 element from the stack and add the operator in between and again store into the stack
*/
string postfixToInfix(string s) {
    int n = s.length();
    stack<string> st;

    for(int i = 0; i < n; i++) {
        if(isOperand(s[i])) {
            st.push(string(1 , s[i]));
        }
        else if(isOperator(s[i])) {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();

            string a = "(" + s1 + s[i] +  s2 + ")";
            st.push(a);
        }
    }
 return st.top();   
}
// prefix to infix
string prefixToInfix(string s) {
    int n = s.length();

    stack<string> st;

    for(int i = n - 1; i >= 0; i--) {
        if(isOperand(s[i])) {
            st.push(string(1 , s[i]));
        }
        else if(isOperator(s[i])) {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();

            string a = "(" + s1 + s[i] + s2 + ")";
            st.push(a);
        }
    }
  return st.top();  
}
//----------------End Here--------------------------------------
int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    firstio();
//---------------------------------------------------------------
   string s = "(a+b)*c-d+f";
   
  






   return 0;
}