// This is very basic and type 1 question from pascal triangle
// Given row no. and column no. we have to return the element on this position
// we have used the formulae of combination i.e, nCr

#include<iostream>
using namespace std;

int main(){
    int r;
    int c;
    int res = 1;

    cout << "Row: ";
    cin >> r;

    cout << "Column: ";
    cin >> c;

    for(int i = 0; i < c; i++){
        res = res * (r-i);
        res = res / (i+1);
    }
    
    cout << res << endl;

    return 0;
}