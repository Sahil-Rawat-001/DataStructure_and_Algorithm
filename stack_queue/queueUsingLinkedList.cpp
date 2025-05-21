#include<iostream>

using namespace std;


// structure of Node
class Node{

  public:
    int data;
    Node* next;

    // constructor
    Node(int value){
        data = value;
        next = nullptr;
    }
};


// Queue structure and ops
class QueueImpl{

    private:
       Node* front;
       Node* rear;
       int size = 0;

    public:
      QueueImpl(){
        front = rear = nullptr;
      }

      // Enqueue: add to rear

      void enqueue(int value){
        Node* newNode = new Node(value);

        if(front == nullptr){
            front = rear = newNode;
        } else{
            rear -> next = newNode;
            rear = newNode;
        }
        size += 1;
      }

      // Dequeue: delete from front

      void dequeue(){
        if(front == nullptr){
            cout << "Underflow: queue is empty." << endl;
        }
        Node* temp = front;
        front = front -> next;
        delete temp;
        size -= 1;
      }

      void top(){
        if(front == nullptr)  cout << "Underflow: queue is empty." << endl;
        cout << "Top: " << rear->data << endl;
      }

      void sizeOfQueue(){
        cout << "Size: " << size << endl;
      }

      void display(){
        if(front == nullptr)  cout << "Underflow: queue is empty." << endl;
        Node* temp = front;

        while(temp != nullptr){
          cout << temp ->data << " ";
          temp = temp -> next;
        }
      }

       
};





int main(){

    QueueImpl q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.sizeOfQueue();
    q.top();    


    return 0;
}