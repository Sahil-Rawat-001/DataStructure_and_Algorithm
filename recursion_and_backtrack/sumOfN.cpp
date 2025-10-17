// We have to make a recursive program which find
// sum of first n natural numbers


#include<iostream>

using namespace std;

int findSum(int n){
    if(n==0) return 0;
    return n+findSum(n-1);
}

// functional recursion program of factorial
int findFactorial1(int n){

    if(n == 0) return 1;
    return n*findFactorial1(n-1);
}

// parameterised recursion program of factorial
int findFactorial2(int n, int result){
    if(n == 0){
        return result;
    }
    return findFactorial2(n-1,result*n);
}

int main(){

    int n = 5;
    cout << "Sum of " << n << " natural numbers: " << findSum(n) << endl;
    cout << "factorial of " << n << " :" <<findFactorial2(n,1) << endl;
}