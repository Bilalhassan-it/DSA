#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int value)
{
    if((rear+1)%SIZE == front)
    cout<<"Queue Full\n";
    else
    {
        if(front == -1) front = 0;
        rear = (rear+1)%SIZE;
        queue[rear] = value;
    }
}

void display()
{
    int i = front;

    while(true)
    {
        cout<<queue[i]<<" ";
        if(i == rear) break;
        i = (i+1)%SIZE;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    display();
}