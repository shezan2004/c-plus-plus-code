#include<iostream>
#include <string>
using namespace std;

class MyStack{
private:
    int Stack[100], top, size;
public:
    MyStack(int size){
        this->size = size;
        top = 0;
    }
    bool isEmpty(){
        if(top == 0){ return true; }
        else{ return false; }
    }
    bool isFull(){
        if(top == size){ return true; }
        else{ return false; }
    }
    bool push(int element){
        if( isFull() == true ){
            cout<<"Stack is full! Can not push."<<endl;
            return false;
        }
        Stack[top++] = element;
        return true;
    }
    bool pop(){
        if(isEmpty() == true){
            cout<<"Stack is empty! Can not pop."<<endl;
            return false;
        }
        top--; return true;
    }
    int topElement(){
        return Stack[top-1];
    }
    void show(){
        if(isEmpty() == true){
            cout<<"Stack is empty! No elements show."<<endl;
        }else{
            cout<<"Stack elements: ";
            for(int i=top-1; i>=0; i--){
                cout<<Stack[i]<<" ";
            }cout<<endl;
        }
    }
};

int performOperation(int operand1, int operand2, char op){
    switch(op){
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

int evaluatePostfixExpression(string& expression){
    MyStack stack(100);

    for(int i=0; i<expression.size();i++){
        char c = expression[i];
        if(isdigit(c)){
            stack.push( c - '0');
            //cout<<"check";
        }else{
            int operand2 = stack.topElement();
            stack.pop();
            int operand1 = stack.topElement();
            stack.pop();

            int result = performOperation(operand1, operand2, c);
            stack.push(result);
        }
    }
    return stack.topElement();
}

int main(){
    string expression = "26*41-/53*+";
    int result = evaluatePostfixExpression(expression);
    cout<<"Result of postfix expression \""<<expression<<"\" is: "<<result<<endl;
}

