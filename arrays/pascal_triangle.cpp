// This type 3 of pascal triangle where we have to print the whole pascal triangle upto rth row;

#include<iostream>
using namespace std;

int main(){
    int r;
    
    cout << "row: ";
    cin >> r;

    for(int i = 0; i < r; i++){
        long long ans = 1;
        for(int j = 0; j <= i; j++){
            cout << ans << " ";
            ans = ans * (i-j);
            ans = ans / (j+1);
        }
        cout << endl;
    }
    return 0;
}