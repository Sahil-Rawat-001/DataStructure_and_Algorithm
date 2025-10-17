#include<iostream>
#include<algorithm>
using namespace std;

string convertDeciToBin(int n){

    string res = "";
    while(n > 0){
        if(n % 2 == 1) res+='1';
        else res+='0';
        n /= 2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int convertBinToDec(string s){
    
    int res = 0;
    int n = s.size();
    int pTwo = 1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '1'){
            res = res + pTwo;
        }
        pTwo = pTwo*2;
    }
    return res;
}

int main(){
    int n = 13;
    string s = "1101";

    cout << convertDeciToBin(n) << endl;
    cout << convertBinToDec(s) << endl;

    return 0;
}