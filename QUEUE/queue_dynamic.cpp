#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void insert(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void remove()
{
    if(front == NULL)
    cout<<"Queue Empty\n";
    else
    {
        cout<<"Deleted: "<<front->data<<endl;
        front = front->next;
    }
}

void display()
{
    Node* temp = front;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);

    display();
}