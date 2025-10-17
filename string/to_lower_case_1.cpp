// It is how we can manually convert and upper case character to lower case
// follow up do it without extra space in place


#include<iostream>

using namespace std;

string manualConversionToLower(string s){
    string r = "";

    for(auto ch : s){
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A' + 'a';
        }
        r += ch;
    }
    return r;
}

string optimizedConversionToLower(string s){

    int j = 0;

    for(int i = 0; i < s.size(); i++){
        int ch = s[i];
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A' +'a';
        }
        s[j++] = ch;
    }
    s.resize(j);
    return s;
}

int main(){
    
    string s = "HELLO EVERY ONE";
    

    // cout << manualConversionToLower(s) << endl;
    cout << optimizedConversionToLower(s) << endl;

    return 0;
}