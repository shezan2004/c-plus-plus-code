#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    // Create the stack and store the letters
    stack<char> st;

    int count = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] != '#'){
            st.push(s[i]);
        }
        else{
            count ++;
        }
    } 

    while(!st.empty() && count > 0){
        
        st.pop();
    }
    
    string ans = "";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
   return ans;
}

int main(){







    return 0;
}