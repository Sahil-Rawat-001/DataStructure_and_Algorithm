/*
  To make a queue using stack needs, using two stack and modify push operation 
  or follow certain rules

  suppose you have to push x which is first element then simply push
  but when you have to push y then follow

  s1 -> s2 take all elements from s1 and store in s2
  y  -> s1 then push y to s1
  s2 -> s1 then take all elements from s2 to s1
*/

#include<iostream>
#include<stack>

using namespace std;

// approach 1 when push operation is less.
class queueUsingStackOne{

    stack<int> s1, s2;

    public:
      
      void push(int value){

        // TC: O(2N)

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(value);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
      }

      void pop(){
        if(s1.empty()){
            cout << "Underflow: queue is empty" << endl;
            return;
        } 
        s1.pop();
      }

      void topEle(){
        if(s1.empty()){
            cout << "Underflow: queue is empty" << endl;
            return;
        }
        cout << "Top: " << s1.top() << endl;
      }

      void display(){
        if(s1.empty()){
            cout << "Underflow: queue is empty" << endl;
            return;
        }

        stack<int> temp = s1;

        while(temp.size()){
            cout << temp.top() << " ";
            temp.pop();
        }
     }
};


// approach 2 when push operation >> top and pop operation
// This approach focuses on optimizing push ops
// we make pop and top operation costly
class queueUsingStackTwo{

    stack<int> s1, s2;

    public: 
      
      void push(int data){
        s1.push(data);
      }

      void pop(){

        if(s2.empty() != 0){
            s1.pop();
        } else{
            // s1 -> s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
      }

      void topEle(){
        if(!s2.empty()){
            cout << "Top: " << s2.top() << endl;
        } else{
            // s1 -> s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            cout << "Top: " << s2.top() << endl;
        }
      }

      void display(){
         if(s2.empty()){
            cout << s1.top() << " ";
            s1.pop();
         } else{
            // s1 -> s2
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }

            while(s2.size()){
                cout << s2.top() << " ";
                s2.pop();
            }
         }
      }
};


int main(){

    // queueUsingStackOne qs1;

    // qs1.push(1);
    // qs1.push(2);
    // qs1.push(3);
    // qs1.push(4);

    // qs1.topEle();
    // qs1.pop();
    // qs1.pop();

    // qs1.topEle();

    // qs1.display();


    queueUsingStackTwo qs2;

    qs2.push(1);
    qs2.push(2);
    qs2.push(3);
    qs2.push(4);
    qs2.push(5);

    qs2.topEle();

    qs2.pop();
    qs2.pop();

    qs2.display();
    
    return 0;
}