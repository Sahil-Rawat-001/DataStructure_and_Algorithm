
#include<iostream>
#include<string>
#include<stack>

using namespace std;

string postfixToPrefix(string exp){

    int i = 0;
    stack<string> st;

    int n = exp.size();

    while (i < n)
    {
       if( (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9')){
            st.push(string(1,exp[i]));
        } else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string newString = exp[i]+t2+t1; // Do This when we encounter an operator while conversion this is imp.
            st.push(newString);
        }
        i++;
    }
    return st.top();
}


int main()
{
  string postfix;

    cout << "Enter an postfix expression: ";
    cin >> postfix;


    cout << "prefix: " << postfixToPrefix(postfix);

  return 0;
}