/*
 * ╔══════════════════════════════════════════════════════════════╗
 * ║           COURIER TRACKING SYSTEM                           ║
 * ║           DSA Project — C++                                 ║
 * ║                                                             ║
 * ║  Data Structures Used:                                      ║
 * ║   1. SinglyLinkedList<T>  — courier records store karna     ║
 * ║   2. Stack (array-based)  — status history track karna      ║
 * ║   3. BST                  — fast search by tracking ID      ║
 * ╚══════════════════════════════════════════════════════════════╝
 */

#include <iostream>
#include <string>
using namespace std;

// ================================================================
//  SECTION 1 — STACK  (tumhara apna static array stack)
//  Har courier ki status history yahan store hogi
//  LIFO: latest status sabse upar
// ================================================================

#define STACK_SIZE 20

struct StatusStack
{
    string statusArr[STACK_SIZE];
    string timeArr[STACK_SIZE];
    int top;

    StatusStack() { top = -1; }

    void push(string status, string time)
    {
        if (top == STACK_SIZE - 1)
            cout << "  [!] Status history full!\n";
        else
        {
            top++;
            statusArr[top] = status;
            timeArr[top]   = time;
        }
    }

    string peek()
    {
        if (top == -1) return "No Status Yet";
        return statusArr[top];
    }

    void printHistory()
    {
        if (top == -1) { cout << "      No history.\n"; return; }
        for (int i = top; i >= 0; i--)
        {
            cout << "      [" << (top - i + 1) << "] "
                 << statusArr[i] << "  —  " << timeArr[i] << "\n";
        }
    }

    bool isEmpty() { return top == -1; }
};


// ================================================================
//  SECTION 2 — COURIER STRUCT
//  Har courier ka data + apni StatusStack
// ================================================================

struct Courier
{
    int         trackingID;
    string      senderName;
    string      receiverName;
    string      destination;
    string      weight;
    StatusStack history;

    Courier() { trackingID = 0; }

    Courier(int id, string sender, string receiver,
            string dest, string wt)
    {
        trackingID   = id;
        senderName   = sender;
        receiverName = receiver;
        destination  = dest;
        weight       = wt;
        history.push("Registered at Office", "Day 1 - 09:00 AM");
    }
};


// ================================================================
//  SECTION 3 — SINGLYLINKEDLIST<T>  (tumhara apna OOP template)
//  Courier objects yahan store honge
// ================================================================

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T     element;
        Node* next;
    };
    Node* head;
    int   size = 0;

public:
    SinglyLinkedList() { head = nullptr; }

    int getSize() { return size; }

    // end mein insert — tumhara apna logic
    void insert(T data)
    {
        Node* temp    = new Node();
        temp->element = data;
        temp->next    = nullptr;

        if (size == 0)
        {
            head = temp;
        }
        else
        {
            Node* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = temp;
        }
        size++;
    }

    // display — tumhara apna display loop
    void display()
    {
        if (size == 0) { cout << "  No couriers in system.\n"; return; }

        Node* curr = head;
        int   num  = 1;

        cout << "\n  ==========================================\n";
        cout << "         ALL COURIERS IN SYSTEM\n";
        cout << "  ==========================================\n";

        while (curr != nullptr)
        {
            cout << "\n  [" << num++ << "] Tracking ID : "
                 << curr->element.trackingID   << "\n";
            cout << "      Sender      : " << curr->element.senderName   << "\n";
            cout << "      Receiver    : " << curr->element.receiverName << "\n";
            cout << "      Destination : " << curr->element.destination  << "\n";
            cout << "      Weight      : " << curr->element.weight << " kg\n";
            cout << "      Status      : " << curr->element.history.peek()<< "\n";
            cout << "  ------------------------------------------\n";
            curr = curr->next;
        }
        cout << "  Total Couriers: " << size << "\n";
    }

    // search by tracking ID — pointer return karo
    T* searchByID(int id)
    {
        Node* curr = head;
        while (curr != nullptr)
        {
            if (curr->element.trackingID == id)
                return &(curr->element);
            curr = curr->next;
        }
        return nullptr;
    }

    // delete by ID — tumhara del logic same rakha
    void deleteByID(int id)
    {
        if (size == 0) return;

        if (head->element.trackingID == id)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->element.trackingID != id)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) return;

        prev->next = curr->next;
        delete curr;
        size--;
    }

    ~SinglyLinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current    = current->next;
            delete temp;
        }
    }
};


// ================================================================
//  SECTION 4 — BST
//  Tracking IDs BST mein — fast O(log n) search
// ================================================================

struct BSTNode
{
    int      trackingID;
    string   receiverName;
    string   destination;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int id, string rec, string dest)
    {
        trackingID   = id;
        receiverName = rec;
        destination  = dest;
        left = right = nullptr;
    }
};

struct CourierBST
{
    BSTNode* root;
    CourierBST() { root = nullptr; }

    BSTNode* insert(BSTNode* node, int id, string rec, string dest)
    {
        if (node == nullptr) return new BSTNode(id, rec, dest);
        if (id < node->trackingID)
            node->left  = insert(node->left,  id, rec, dest);
        else if (id > node->trackingID)
            node->right = insert(node->right, id, rec, dest);
        return node;
    }

    void add(int id, string rec, string dest)
    {
        root = insert(root, id, rec, dest);
    }

    BSTNode* search(BSTNode* node, int id)
    {
        if (node == nullptr)        return nullptr;
        if (node->trackingID == id) return node;
        if (id < node->trackingID)  return search(node->left,  id);
        return search(node->right, id);
    }

    void searchAndShow(int id)
    {
        BSTNode* res = search(root, id);
        if (res == nullptr)
            cout << "\n  [!] ID " << id << " not found in BST.\n";
        else
        {
            cout << "\n  [BST Result] ID: " << res->trackingID
                 << "  Receiver: " << res->receiverName
                 << "  Dest: "     << res->destination << "\n";
        }
    }

    void inorder(BSTNode* node)
    {
        if (node == nullptr) return;
        inorder(node->left);
        cout << "  ID: " << node->trackingID
             << "  ->  " << node->receiverName
             << "  ->  " << node->destination << "\n";
        inorder(node->right);
    }

    void showSorted() { cout << "\n  [Sorted by ID — BST Inorder]\n"; inorder(root); }
};


// ================================================================
//  SECTION 5 — MAIN
// ================================================================

int main()
{
    SinglyLinkedList<Courier> courierList;  // tumhara linked list
    CourierBST bst;                         // BST

    int choice;
    int idCounter = 1001;

    // ---- Sample Data — 3 couriers preloaded ----
    Courier c1(1001, "Ali Raza",    "Sara Khan",  "Karachi",   "2.5");
    c1.history.push("Picked Up",               "Day 1 - 02:00 PM");
    c1.history.push("In Transit — Lahore Hub", "Day 2 - 10:00 AM");
    courierList.insert(c1);
    bst.add(1001, "Sara Khan", "Karachi");

    Courier c2(1002, "Bilal Ahmed", "Zara Ali",   "Lahore",    "0.5");
    c2.history.push("Picked Up",               "Day 1 - 11:00 AM");
    courierList.insert(c2);
    bst.add(1002, "Zara Ali", "Lahore");

    Courier c3(1003, "Usman Tariq", "Hira Baig",  "Islamabad", "5.0");
    c3.history.push("Picked Up",               "Day 2 - 09:00 AM");
    c3.history.push("In Transit — Pindi Hub",  "Day 2 - 04:00 PM");
    c3.history.push("Out for Delivery",        "Day 3 - 08:00 AM");
    courierList.insert(c3);
    bst.add(1003, "Hira Baig", "Islamabad");

    idCounter = 1004;

    cout << "\n  Welcome to Courier Tracking System!\n";
    cout << "  3 sample couriers loaded. Try ID 1001, 1002, 1003.\n";

    do
    {
        cout << "\n  ==========================================\n";
        cout << "       COURIER TRACKING SYSTEM v1.0\n";
        cout << "  ==========================================\n";
        cout << "  1.  Register New Courier\n";
        cout << "  2.  Update Courier Status\n";
        cout << "  3.  Track Courier  (Full History — Stack)\n";
        cout << "  4.  Search by ID   (BST — Fast Search)\n";
        cout << "  5.  Display All    (Linked List)\n";
        cout << "  6.  Display Sorted (BST Inorder)\n";
        cout << "  7.  Mark as Delivered\n";
        cout << "  8.  Cancel Courier\n";
        cout << "  9.  Exit\n";
        cout << "  ==========================================\n";
        cout << "  Enter choice: ";
        cin  >> choice;

        // 1 — Register
        if (choice == 1)
        {
            string sender, receiver, dest, wt;
            cout << "\n  -- Register New Courier --\n";
            cout << "  Sender Name   : "; cin.ignore(); getline(cin, sender);
            cout << "  Receiver Name : ";               getline(cin, receiver);
            cout << "  Destination   : ";               getline(cin, dest);
            cout << "  Weight (kg)   : ";               getline(cin, wt);

            Courier newC(idCounter, sender, receiver, dest, wt);
            courierList.insert(newC);
            bst.add(idCounter, receiver, dest);

            cout << "\n  [+] Registered! Tracking ID: " << idCounter << "\n";
            idCounter++;
        }

        // 2 — Update Status
        else if (choice == 2)
        {
            int    id;
            string status, time;
            cout << "\n  Tracking ID : "; cin >> id;

            Courier* c = courierList.searchByID(id);
            if (c == nullptr)
                cout << "  [!] Courier " << id << " not found!\n";
            else
            {
                cout << "  New Status  : "; cin.ignore(); getline(cin, status);
                cout << "  Date & Time : ";               getline(cin, time);
                c->history.push(status, time);  // stack mein push
                cout << "  [+] Status updated: " << status << "\n";
            }
        }

        // 3 — Track (Stack history)
        else if (choice == 3)
        {
            int id;
            cout << "\n  Tracking ID: "; cin >> id;

            Courier* c = courierList.searchByID(id);
            if (c == nullptr)
                cout << "  [!] Invalid ID!\n";
            else
            {
                cout << "\n  ==========================================\n";
                cout << "  Tracking ID  : " << c->trackingID   << "\n";
                cout << "  Sender       : " << c->senderName   << "\n";
                cout << "  Receiver     : " << c->receiverName << "\n";
                cout << "  Destination  : " << c->destination  << "\n";
                cout << "  Weight       : " << c->weight << " kg\n";
                cout << "  Current      : " << c->history.peek() << "\n";
                cout << "\n  -- History (Latest First) --\n";
                c->history.printHistory();
                cout << "  ==========================================\n";
            }
        }

        // 4 — BST Search
        else if (choice == 4)
        {
            int id;
            cout << "\n  Enter ID to search (BST): "; cin >> id;
            bst.searchAndShow(id);
        }

        // 5 — Display All
        else if (choice == 5)
        {
            courierList.display();
        }

        // 6 — BST Sorted
        else if (choice == 6)
        {
            bst.showSorted();
        }

        // 7 — Deliver
        else if (choice == 7)
        {
            int id;
            cout << "\n  Tracking ID to Deliver: "; cin >> id;
            Courier* c = courierList.searchByID(id);
            if (c == nullptr)
                cout << "  [!] Not found!\n";
            else
            {
                c->history.push("DELIVERED", "Final");
                courierList.deleteByID(id);
                cout << "  [+] Courier " << id << " DELIVERED and removed.\n";
            }
        }

        // 8 — Cancel
        else if (choice == 8)
        {
            int id;
            cout << "\n  Tracking ID to Cancel: "; cin >> id;
            Courier* c = courierList.searchByID(id);
            if (c == nullptr)
                cout << "  [!] Not found!\n";
            else
            {
                c->history.push("CANCELLED", "Final");
                courierList.deleteByID(id);
                cout << "  [+] Courier " << id << " CANCELLED and removed.\n";
            }
        }

        else if (choice == 9)
            cout << "\n  Goodbye!\n\n";
        else
            cout << "\n  [!] Invalid choice.\n";

    } while (choice != 9);

    return 0;
}



//pwd
//g++ courier.cpp -o courier.exe
//.\courier.exe