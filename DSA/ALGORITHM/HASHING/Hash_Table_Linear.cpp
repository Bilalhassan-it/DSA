#include <iostream>
// Hash Table with Linear Probing
class HashTableLinear
{
    private:
        int* container;
        int size;
        const int DELETED = -999999;
        const int EMPTY = -999998;
        
    public:
        const int CAPACITY = 10;

        HashTableLinear(int capacity) : size(capacity)
        {
            container = new int[capacity]();

            for (int i = 0; i < size; i++)
            {
                container[i] = EMPTY;
            }
            
        }
        HashTableLinear() : HashTableLinear(CAPACITY) {}

        int insert(int element) // returns the index where value is inserted
        {
            int hashed = hash_method(element);

            int i = 0;
            while (container[hashed] != EMPTY && container[hashed] != DELETED)
            {
                if (i == size)
                {
                    std::cout << "Table is full\n";
                    return -1;
                }
                i++;
                hashed = (hashed + 1) % size;
            }

            container[hashed] = element;
            return hashed;
        }
        int search(int element)
        {
            int hashed = hash_method(element);

            int i = 0;
            while (container[hashed] != EMPTY)
            {
                if (container[hashed] == element) return hashed;
            
                if (i == size)
                {
                    std::cout << "Element not found\n";
                    return -1;
                }
                i++;
                hashed = (hashed + 1) % size;
            }

            std::cout << "Element not found\n";
            return -1;
        }
        void del(int element)
        {
            int i = search(element);

            if (i == -1) return;

            container[i] = DELETED;
        }
        void delIndex(int index)
        {
            if (index >= 0 && index < size)
            {
                container[index] = DELETED;
            }
            
        }
        void display()
        {
            std::cout << "\n====Hash Table====\n";
            for (int i = 0; i < size; i++)
            {
                if (container[i] == EMPTY || container[i] == DELETED) std::cout << "_\n";
                else std::cout << container[i] << std::endl;   
            }
            std::cout << "~~~~Hash Table~~~~\n\n";
            
        }

    
    protected:
        int hash_method(int val)
        {
            return val % size;
        }

    public:
        ~HashTableLinear()
        {
            delete[] container;
        }
};