#include<bits/stdc++.h>

# define ll long long int;

using namespace std;
class minStack{
    public:
    stack<ll> st;
    ll mn;
    minStack(){
      this->mn =INT_MAX;
  
    }
    void push(int val){
        if(!this->st.empty()){
          this->mn =val;
          this->st.push(val);
        }else{
          this->st.push(val - this->min){
            if(this->mn > val){
              this->mn = val;
            }
          }
        }
    }
    void pop(){
      if(! this->st.empty()){
        if(this->st.top()>=0){
          this->st.pop();
        }else{
          this->mn = this->mn - this->st.top();
          this->st.pop();
        }
      }

    }
    int top(){
         if(this->st.size()==1){
          return this->st.top();
         }else if(this->st.top()<0){
          return this->mn;
         }else if(this->st.top()>0){
          return this->mn + this->st.top();
         }
    }
    int getMin(){
          return this->mn;
    }
 }; 



int main(){


    

    return 0;
}