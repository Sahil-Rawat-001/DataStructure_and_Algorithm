// Here we are implementing stack using linked list
// because in array there is boudation of size 

#include<iostream>

using namespace std;


// Node Structure
class Node{

  public:
    int data;
    Node* next;


    /*
        A constructor is a special function in a class that:

        Has the same name as the class.

        Runs automatically when an object of the class is created.

        Is used to initialize variables of the class.

    */

    // constructor 
    Node(int value){
        data = value;
        next = nullptr;
    }
};


class Stack{

    private:
       Node* top;
       int size = 0;

    public:
      Stack(){
        top = nullptr;
      }

      void push(int value){
        Node* newNode = new Node(value);
        newNode -> next = top;
        top = newNode;
        size += 1;
      }

      void pop(){
        if(top == nullptr){
          cout << "UnderFlow: Stack is empty." << endl;
        } else{
          Node* temp = top;
          top = top -> next;
          delete temp;
          size -= 1;
        }
      }

      void peek(){
        if(top == nullptr){
          cout <<  "UnderFlow: Stack is empty." << endl;
        }
        cout << top->data << endl;
      }

      void display(){
        if(top == nullptr){
          cout <<  "UnderFlow: Stack is empty." << endl;
        }
        Node* temp = top;

        while(temp != nullptr){
          cout << temp -> data << " ";
          temp = temp -> next;
        }
      }

      void sizeOfStack(){
        cout << "Size: " << size << endl;
      }

      // Destructor to free memory
      ~Stack() {
        while (!(top == nullptr)) {
          pop();
        }
      }
};

int main(){

  Stack stk;

  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);

  stk.display();

  stk.sizeOfStack();

  stk.pop();
  stk.pop();

  stk.sizeOfStack();

  stk.peek();

  stk.display();





  return 0;
}