#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if(top == NULL)
    cout<<"Stack Empty\n";
    else
    {
        cout<<"Deleted: "<<top->data<<endl;
        top = top->next;
    }
}

void display()
{
    Node* temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
}