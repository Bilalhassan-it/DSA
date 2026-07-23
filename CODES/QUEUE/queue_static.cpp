#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int value)
{
    if(rear == SIZE-1)
    cout<<"Queue Full\n";
    else
    {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = value;
    }
}

void remove()
{
    if(front == -1)
    cout<<"Queue Empty\n";
    else
    {
        cout<<"Deleted: "<<queue[front]<<endl;
        front++;
    }
}

void display()
{
    for(int i=front;i<=rear;i++)
    cout<<queue[i]<<" ";
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    display();
}