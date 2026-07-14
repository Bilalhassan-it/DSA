#include<iostream>
using namespace std;

struct Node{
    int data; 
    int next;

    Node(int value){
        data =value;
        next = NULL;
    }
};

// ============ LINKED LIST CLASS ============
struct LinkedList {
    Node* head;     // pehle node ka pointer
    
    LinkedList() { head = NULL; } // shuru mein khaali
    
 // ---- INSERT AT BEGINNING ----
    void insertFront(int val) {
        Node* newNode = new Node(val); // naya node banao
        newNode->next = head;          // naye ka next = purana head
        head = newNode;               // head update karo
        cout << val << " inserted at front\n";
    }
    
 // ---- INSERT AT END ----
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {    // agar list khaali hai
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)  // end tak jao
            temp = temp->next;
        temp->next = newNode;       // last node ka next = naya node
        cout << val << " inserted at end\n";
    }
    
 // ---- INSERT AFTER A VALUE ----
    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != target)
            temp = temp->next;
        if (temp == NULL) {
            cout << target << " not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;  // naye ka next = target ka next
        temp->next = newNode;        // target ka next = naya node
        cout << val << " inserted after " << target << "\n";
    }
    
 // ---- DELETE A VALUE ----
    void deleteNode(int val) {
        if (head == NULL) { cout << "List empty!\n"; return; }
        
        // agar head delete karna hai
        if (head->data == val) {
            Node* temp = head;
            head = head->next;  // head aage badh jaye
            delete temp;
            cout << val << " deleted\n";
            return;
        }
        
     // middle ya end mein dhoondhna
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) { cout << val << " not found!\n"; return; }
        
        prev->next = curr->next;  // previous ka next skip karo current ko
        delete curr;
        cout << val << " deleted\n";
    }
    
    // ---- SEARCH ----
    bool search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << val << " found!\n";
                return true;
            }
            temp = temp->next;
        }
        cout << val << " not found!\n";
        return false;
    }
    
    // ---- COUNT ELEMENTS ----
    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) { cnt++; temp = temp->next; }
        cout << "Total nodes: " << cnt << "\n";
        return cnt;
    }
    
    // ---- DELETE MIDDLE ELEMENT ----
    void deleteMiddle() {
        if (head == NULL) return;
        int n = count();
        int mid = n / 2;  // middle index
        Node* temp = head;
        for (int i = 0; i < mid - 1; i++)
            temp = temp->next;
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << toDelete->data << " (middle) deleted\n";
        delete toDelete;
    }
    
    // ---- DISPLAY ----
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    // ---- REVERSE ----
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;  // next save karo
            curr->next = prev;  // link ulti karo
            prev = curr;        // prev aage badho
            curr = next;        // curr aage badho
        }
        head = prev;  // head ab last node hai
        cout << "List reversed!\n";
    }
};

int main() {
    LinkedList ll;
    
    ll.insertEnd(10);
    ll.insertEnd(20);
    ll.insertEnd(30);
    ll.insertEnd(40);
    ll.insertEnd(50);
    ll.display();         // 10->20->30->40->50->NULL
    
    ll.insertFront(5);
    ll.display();         // 5->10->20->30->40->50->NULL
    
    ll.insertAfter(20, 25);
    ll.display();         // 5->10->20->25->30->40->50->NULL
    
    ll.deleteNode(25);
    ll.display();
    
    ll.search(30);
    ll.count();
    
    ll.deleteMiddle();
    ll.display();
    
    ll.reverse();
    ll.display();
    
    return 0;
}