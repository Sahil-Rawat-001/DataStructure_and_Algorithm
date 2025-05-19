// Stack is a data structure which works on LIFO principle
// Last In First Out

#include<iostream>

using namespace std;



class StackImpl{
    
    int top = -1;
    int arr[100];

    public:
        
        void push(int x){
            
            if(top > 99){
                cout << endl << "Overflow: Stack is full" << endl;
            }
            top += 1;
            arr[top] = x;
        }

        void peek(){
            if(top == -1){
                cout << endl << "Underflow: stack is empty" << endl;
            }
            cout << arr[top] << endl;
        }

        void pop(){
            if(top == -1){
                cout << endl << "Underflow: stack is empty" << endl;
            }
            cout << arr[top] << " removed from stack" << endl;
            top = top - 1;          
        }

        void size(){
            if(top == -1){
                cout << "Size: " << 0 << endl;
            }
            cout << "Size: " << top+1 << endl;
        }
};


int main(){

    StackImpl stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    stk.peek();

    stk.pop();

    stk.peek();

    stk.size();

    return 0;
}

