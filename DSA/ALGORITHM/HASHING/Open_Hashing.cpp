
#include <iostream>
#include "../Linked-List/SLL/single_linked_list2.cpp"
using namespace std;

class OpenHashTable{
    private:
        SinglyLinkedList<int>** table;
        int size;

    public:
        static const int CAPACITY = 5;
        
        OpenHashTable() : OpenHashTable(CAPACITY) {};
        OpenHashTable(int size) : size(size)
        {
            table = new SinglyLinkedList<int>*[size];

            for (int i = 0; i < size; i++)
            {
                table[i] = nullptr;
            }
        }

    void insert(int n)
    {
        int hash = hash_method(n);
        
        if (table[hash] == nullptr)
        {
            table[hash] = new SinglyLinkedList<int>();
        }

        table[hash]->insert(n);
    }

    int search(int n)
    {
        int hash = hash_method(n);

        if (table[hash] == nullptr) return -1;

        int output = table[hash]->search(n);

        return (output == -1) ? -1 : hash;
    }

    void del(int n)
    {
        int hash = hash_method(n);

        if (table[hash] == nullptr) return;

        table[hash]->del(n);

        if (table[hash]->getSize() == 0)
        {
            SinglyLinkedList<int>* temp = table[hash];
            delete temp;
            table[hash] = nullptr;
        }
    }
    
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Index " << i << ":\n";
            if (table[i] != nullptr)
            {
                table[i]->display();
            }
            std::cout << std::endl;
            
        }
    }

    ~OpenHashTable()
    {
        for (int i = 0; i < size; i++)
        {
            delete table[i];
        }

        delete[] table;
    }
    protected:
        int hash_method(int val)
        {
            return val % size;
        }
};

int main()
{
    OpenHashTable oht;

    int choice;
    int userInput;
    int t;
    std::cout << "Choose any one of the following: " << std::endl;
    std::cout << "1 to Insert\n" << "2 to Search\n" << "3 to Delete\n" <<
    "4 to Display\n" << "5 to Exit\n" << std::endl;
    
    while (true)
    {    
        std::cout << "Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Input integer to insert: ";
            std::cin >> userInput;
            oht.insert(userInput);
            break;
        case 2:
            std::cout << "Input integer to search: ";
            std::cin >> userInput;
            t = oht.search(userInput);
            if (t == -1) std::cout << "Not Found\n";
            else std::cout << t << std::endl;
            break;
        case 3:
            std::cout << "Input integer to delete: ";
            std::cin >> userInput;
            oht.del(userInput);
            break;
        case 4:
            oht.display();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
        }
    }
    return 0;
}

