// Queue is a data structure that follow FIFO rule
// First In First Out

/*

  In queue insertion  =  enqueue => from rear/tail side
  In queue deletion   =  dequeue => from front/head side

  In circuler queue the condition to check if queue is full or not is if (end+1) % sizeofqueue == front

  when we enter or enqueue an element in queue then we do no have to do rear++ we have to do rear = (rear + 1) % sizeofqueue

  when we delete or dequeue an element in queue then we do no have to do front++ we have to do front = (front + 1) % sizeofqueue

*/


#include<iostream>

using namespace std;


class QueueImpl{

    int start = -1;
    int end   = -1;
    static const int size  = 10;
    int arr[size];
    int curr_size = 0;


    public:

      void push(int x){
        if(curr_size == size){
            cout << "Overflow: Queue is full" << endl;
        }
        if(curr_size == 0){
            start = 0;
            end   = 0;
        }
        else{
            end = (end+1) % size;
        }
        arr[end] = x;
        curr_size += 1;
      }

      void pop(){
        if(curr_size == 0){
            cout << "Underflow: Queue is empty" << endl;
        }
        if(curr_size == 1){
            start = end = -1;
        } else{
            cout << arr[start] << " is deleted. " << endl;
            start = (start + 1) % size;
        }
        curr_size -= 1;
      }

      void top(){
        if(curr_size == 0) cout << "Underflow: Queue is empty" << endl;
        cout << "Top element is: "  << arr[start] << endl;
      }
      
      void sizeofqueue(){
        cout << "size: " << curr_size << endl;
      }

};



int main(){

    QueueImpl q1;

    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    q1.top();
    q1.sizeofqueue();

    q1.pop();
    q1.pop();

    q1.top();
    q1.sizeofqueue();

    return 0;
}