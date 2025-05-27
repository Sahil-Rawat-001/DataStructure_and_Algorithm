#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function for operator prededence checking
int precedence(char op){

    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}


string infixToPostfix(string exp){
    stack<int> st;
    int i = 0;
    string ans = "";
    
    int n = exp.size();

    while(i < n){
        // First if check if incoming char is operand
        if( (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9')){
            ans += exp[i];
        } else if (exp[i] == '('){ // second if check if incoming expression value is  '(' opening bracket
            st.push(exp[i]);
        } else if (exp[i] == ')'){
            while(!st.empty() && st.top() != '('){ // second if check if incoming expression value is  ')' closing bracket
                ans += st.top(); // then print and pop the stack until opening bracket is not found.
                st.pop();
            }
            st.pop();
        } else{
            // Pop operator from stack with higher or equal precedence
            while(!st.empty() && precedence(st.top()) >= precedence(exp[i])){
                ans += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
        i++;
    }

    // If there is anything left in stack pop it and print it
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main(){
    
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix);
    return 0;
}