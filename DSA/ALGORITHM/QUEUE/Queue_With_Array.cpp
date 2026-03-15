#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue
{
    int size;
    int *arr;
    int front;
    int rear;
};
int isfull(struct Queue *q)
{
    if (q->rear == q->size - 1)
        return 1;
}
else
{
    return 0;
};

int isempty(struct Queue *q)
{
    if (q->rear == q->front)
        return 1;
}
else
{
    return 0;
};
void enqueue(struct Queue *q, int value)
{
    if (isfull(q))
    {
        cout << "Queue is Full";
    };
    else
    {
        q.rear++;
        q.arr[q.rear] = value;
        cout << "Enqueued value is: " << value;
    }
};

int main()
{
    struct Queue q;
    {
        q.size = 100;
        q.front = q.rear = -1;
        q.arr = (int *)malloc(q.size * sizeof(int));
        if (isempty(&q))
        {
            cout << "Memory error";
            return -1;
        }

        return 0;
        // Enqueue some values
        enqueue(&q, 10);
        enqueue(&q, 20);
        enqueue(&q, 30);
        if (isempty(&q))
        {
            cout << "Memory error";
            return -1;
        }
        return 0;
    };
    return 0;
}