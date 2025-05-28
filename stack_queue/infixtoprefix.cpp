#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

// Function for operator prededence checking
int precedence(char op){

    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}


string infixToPrefix(string exp){
    stack<char> st;
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

            if(exp[i] == '^'){
                while(!st.empty() && precedence(exp[i]) <= precedence(st.top())){
                    ans += st.top();
                    st.pop();
                }
            } else {
                while(!st.empty() && precedence(st.top()) > precedence(exp[i])){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(exp[i]);
        }
        i++;
    } //A + (B - C) * D ^ E ^ F / G

    // If there is anything left in stack pop it and print it
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}


int main(){
    
    string infix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    cout << "Prefix: " << infixToPrefix(infix);
    return 0;
}