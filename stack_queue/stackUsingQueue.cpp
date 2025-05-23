// In this code we are implementing stack using queue
// for this we have to modify push operation

/*
   suppose we push 2, 4, 5, and 8 in queue

   it will look like this front 2 4 5 8 rear

   but in stack it will look like
   8 <- top
   5
   4
   2

   so to do this we have to do

   when there is push 2 we simply push
   but when we push 4 we have to follow some rules i.e,

   then we push q.top() again i.e, 2
   then it will look like this  2 4 2
   then we pop from the queue
   then it will look like this 4 2 it is like stack

   if we query top it will show 4 which is same in stack and pop operation always occur from front side or
   from top element side
*/
#include <iostream>
#include <queue>

using namespace std;

class stackImplUsingQueue
{

    queue<int> q;

public:
    void push(int value)
    {

        int size = q.size();

        q.push(value);

        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (!q.empty())
        {
            q.pop();
        }
        else
        {
            cout << "Stack is empty\n";
        }
    }

    int top()
    {
        if (!q.empty())
            return q.front();
        return -1; // or throw exception
    }

    bool empty()
    {
        return q.empty();
    }

    void display(){

        queue<int> temp = q;

        while(!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }
    }
};

int main()
{
    stackImplUsingQueue sq;

    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);

    cout << sq.top() << endl;

    sq.pop();

    sq.display();
   
    return 0;
}