
#include<iostream>
#include<string>
#include<stack>

using namespace std;

string postfixToPrefix(string exp){

    int i = 0;
    stack<string> st;

    int n = exp.size() - 1;

    while (n >= 0)
    {
       if( (exp[n] >= 'A' && exp[n] <= 'Z') || (exp[n] >= 'a' && exp[n] <= 'z') || (exp[n] >= '0' && exp[n] <= '9')){
            st.push(string(1,exp[n]));
        } else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string newString = t1+t2+exp[n]; // Do This when we encounter an operator while conversion this is imp.
            st.push(newString);
        }
        n--;
    }
    return st.top();
}


int main()
{
  string prefix;

    cout << "Enter an prefix expression: ";
    cin >> prefix;


    cout << "postfix: " << postfixToPrefix(prefix);

  return 0;
}