#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value)
{
    if(top == SIZE-1)
    cout<<"Stack Overflow\n";
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(top == -1)
    cout<<"Stack Underflow\n";
    else
    {
        cout<<"Deleted: "<<stack[top]<<endl;
        top--;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    cout<<stack[i]<<" ";
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    cout<<endl;

    pop();

    display();
}