// This type 2 of pascal triangle where we have to print the elements of the given row;

#include<iostream>
using namespace std;

int main(){
    int r;
    int ans = 1;
    cout << "row: ";
    cin >> r;


    cout << ans << " ";

    for(int i = 1; i < r; i++){
        ans = ans * (r-i);
        ans = ans / i;
        cout << ans << " ";
    }
    return 0;
}