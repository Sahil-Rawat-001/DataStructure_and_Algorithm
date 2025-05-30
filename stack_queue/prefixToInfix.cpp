#include<iostream>
#include<string>
#include<stack>

using namespace std;

string prefixToInfix(string exp){

    int i = 0;
    stack<string> st;

    int n = exp.size()-1;

    while (n >= i)
    {
       if( (exp[n] >= 'A' && exp[n] <= 'Z') || (exp[n] >= 'a' && exp[n] <= 'z') || (exp[n] >= '0' && exp[n] <= '9')){
            st.push(string(1,exp[n]));
        } else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string newString = '('+t1+exp[n]+t2+')';
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


    cout << "Infix: " << prefixToInfix(prefix);

  return 0;
}