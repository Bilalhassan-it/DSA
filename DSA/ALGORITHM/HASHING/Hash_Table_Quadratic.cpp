#include <iostream>
// Hash Table with Quadratic Probing
class HashTableQuadratic
{
    private:
        int* container;
        int size;
        const int DELETED = -999999;
        const int EMPTY = -999998;
        
    public:
        const int CAPACITY = 10;

        HashTableQuadratic(int capacity) : size(capacity)
        {
            container = new int[capacity]();

            for (int i = 0; i < size; i++)
            {
                container[i] = EMPTY;
            }
            
        }
        HashTableQuadratic() : HashTableQuadratic(CAPACITY) {}

        int insert(int element)
        {
            int original_hash = hash_method(element);
            
            for (int i = 0; i < size; i++)
            {
                int hashed = (original_hash + (i * i)) % size;
                
                if (container[hashed] == EMPTY || container[hashed] == DELETED)
                {
                    container[hashed] = element;
                    return hashed;
                }
            }
            
            std::cout << "Table is full\n";
            return -1;
        }

        int search(int element)
        {
            int original_hash = hash_method(element);
            
            for (int i = 0; i < size; i++)
            {
                int hashed = (original_hash + (i * i)) % size;
                
                if (container[hashed] == EMPTY)
                {
                    std::cout << "Element not found\n";
                    return -1;
                }
                
                if (container[hashed] == element)
                {
                    return hashed;
                }
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
        ~HashTableQuadratic()
        {
            delete[] container;
        }
};