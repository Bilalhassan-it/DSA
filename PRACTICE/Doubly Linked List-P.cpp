#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;   // pichla node
    Node* next;   // agla node
    Node(int v) { data=v; prev=next=NULL; }
};

struct DLL {
    Node* head;
    DLL() { head = NULL; }
    
    // ---- INSERT AT FRONT ----
    void insertFront(int val) {
        Node* n = new Node(val);
        if (head != NULL) head->prev = n;  // purane head ka prev = naya
        n->next = head;
        head = n;
    }
    
    // ---- INSERT AT END ----
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;  // DLL mein prev bhi set karo
    }
    
    // ---- INSERT AFTER ----
    void insertAfter(int target, int val) {
        Node* t = head;
        while (t && t->data != target) t = t->next;
        if (!t) return;
        Node* n = new Node(val);
        n->next = t->next;
        n->prev = t;
        if (t->next) t->next->prev = n;
        t->next = n;
    }
    
    // ---- DELETE ----
    void deleteNode(int val) {
        Node* t = head;
        while (t && t->data != val) t = t->next;
        if (!t) return;
        if (t->prev) t->prev->next = t->next;  // prev ka next update
        else head = t->next;                    // head tha
        if (t->next) t->next->prev = t->prev;  // next ka prev update
        delete t;
        cout << val << " deleted from DLL\n";
    }
    
    // ---- DISPLAY FORWARD ----
    void displayForward() {
        Node* t = head;
        cout << "Forward: ";
        while (t) { cout << t->data << " <-> "; t = t->next; }
        cout << "NULL\n";
    }
    
    // ---- DISPLAY BACKWARD ----
    void displayBackward() {
        Node* t = head;
        while (t->next) t = t->next;  // end tak jao
        cout << "Backward: ";
        while (t) { cout << t->data << " <-> "; t = t->prev; }
        cout << "NULL\n";
    }
};

int main() {
    DLL dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.displayForward();   // 10 <-> 20 <-> 30 <-> NULL
    dll.insertAfter(20, 25);
    dll.displayForward();   // 10 <-> 20 <-> 25 <-> 30 <-> NULL
    dll.deleteNode(20);
    dll.displayForward();   // 10 <-> 25 <-> 30 <-> NULL
    dll.displayBackward();
    return 0;
}