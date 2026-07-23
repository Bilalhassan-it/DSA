#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);
    int i = 1;

    while(hashTable[index] != 0)
    {
        index = (index + i*i) % SIZE;
        i++;
    }

    hashTable[index] = key;
}

void display()
{
    for(int i=0;i<SIZE;i++)
    cout<<hashTable[i]<<" ";
}

int main()
{
    insert(10);
    insert(20);
    insert(15);

    display();
}