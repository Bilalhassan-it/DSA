/*
 * ╔══════════════════════════════════════════════════════════════╗
 * ║           COURIER TRACKING SYSTEM                           ║
 * ║           DSA Project — C++                                 ║
 * ║                                                             ║
 * ║  Data Structures Used:                                      ║
 * ║   • SinglyLinkedList<T>  — Courier storage (your code)     ║
 * ║   • BSTNode / BST funcs  — Fast ID search (your code)      ║
 * ║   • Stack (static array) — Status history (your code)      ║
 * ╚══════════════════════════════════════════════════════════════╝
 */

#include <iostream>
#include <string>
using namespace std;

// ================================================================
//   SECTION 1 — STACK (your exact code, adapted for strings)
//   Use: Courier ki status history track karna (LIFO)
//   Latest status = top of stack
// ================================================================

#define STACK_SIZE 20  // ek courier ki max 20 status updates

struct StatusStack {
    string stack[STACK_SIZE];  // string stack for status messages
    string timeStack[STACK_SIZE]; // har status ka time
    int top = -1;

    // status push karo
    void push(string status, string time) {
        if (top == STACK_SIZE - 1) {
            cout << "   [!] Status history full!\n";
        } else {
            top++;
            stack[top] = status;
            timeStack[top] = time;
        }
    }

    // latest status dekho (pop nahi, sirf peek)
    string peekStatus() {
        if (top == -1) return "Not Registered";
        return stack[top];
    }

    // poori history display karo (latest first — LIFO)
    void displayHistory() {
        if (top == -1) {
            cout << "   No history available.\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "   [" << (top - i + 1) << "] "
                 << stack[i] << "  —  " << timeStack[i] << "\n";
        }
    }

    // check karo koi status hai ya nahi
    bool isEmpty() { return top == -1; }
};


// ================================================================
//   SECTION 2 — COURIER STRUCT
//   Har courier ka data + uski StatusStack
// ================================================================

struct Courier {
    int    trackingID;
    string senderName;
    string receiverName;
    string destination;
    string weight;
    string phone;          // receiver ka contact
    StatusStack history;   // YOUR stack — har courier ki history
    Courier* next;         // linked list ka next pointer

    Courier(int id, string sender, string receiver,
            string dest, string wt, string ph) {
        trackingID  = id;
        senderName  = sender;
        receiverName = receiver;
        destination = dest;
        weight      = wt;
        phone       = ph;
        next        = nullptr;
        // register hote hi pehli status add karo
        history.push("Registered at Warehouse", "Day 1 - 09:00 AM");
    }
};


// ================================================================
//   SECTION 3 — SINGLY LINKED LIST (your exact template class)
//   Adapted: T = Courier* (pointer store karenge)
//   Use: Saare couriers ki linked list
// ================================================================

template <typename T>
class SinglyLinkedList {
    private:
        struct Node {
            T element;
            Node* next;
        };
        Node* head;
        int size = 0;

    public:
        SinglyLinkedList() { head = nullptr; }

        int getSize() { return size; }

        // end mein insert karo
        void insert(T data) {
            Node* temp = new Node();
            temp->element = data;
            temp->next = nullptr;
            if (size == 0) {
                head = temp;
            } else {
                Node* curr = head;
                while (curr->next != nullptr)
                    curr = curr->next;
                curr->next = temp;
            }
            size++;
        }

        // ID se Courier* dhoondho
        T searchByID(int id) {
            Node* curr = head;
            while (curr != nullptr) {
                if (curr->element->trackingID == id)
                    return curr->element;
                curr = curr->next;
            }
            return nullptr;
        }

        // ID se delete karo
        bool deleteByID(int id) {
            if (size == 0) return false;

            // head check
            if (head->element->trackingID == id) {
                Node* temp = head;
                head = head->next;
                delete temp;
                size--;
                return true;
            }

            // baaki list mein dhoondho
            Node* curr = head;
            while (curr->next != nullptr) {
                if (curr->next->element->trackingID == id) {
                    Node* temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                    size--;
                    return true;
                }
                curr = curr->next;
            }
            return false;
        }

        // saare couriers display karo
        void display() {
            if (size == 0) {
                cout << "\n   No couriers in system.\n";
                return;
            }
            Node* curr = head;
            int count = 1;
            while (curr != nullptr) {
                Courier* c = curr->element;
                cout << "\n   ┌─────────────────────────────────────┐\n";
                cout << "   │  [" << count++ << "] Tracking ID : " << c->trackingID << "\n";
                cout << "   │  Sender      : " << c->senderName   << "\n";
                cout << "   │  Receiver    : " << c->receiverName << "\n";
                cout << "   │  Destination : " << c->destination  << "\n";
                cout << "   │  Weight      : " << c->weight       << "\n";
                cout << "   │  Phone       : " << c->phone        << "\n";
                cout << "   │  Status      : " << c->history.peekStatus() << "\n";
                cout << "   └─────────────────────────────────────┘\n";
                curr = curr->next;
            }
            cout << "\n   Total Couriers: " << size << "\n";
        }

        // head pointer do (BST banana ke liye)
        Node* getHead() { return head; }

        ~SinglyLinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
};


// ================================================================
//   SECTION 4 — BST (your exact code, adapted for Courier IDs)
//   Use: Fast search by Tracking ID — O(log n)
// ================================================================

struct BSTNode {
    int     trackingID;    // key for BST
    string  receiverName;  // quick lookup info
    string  destination;
    BSTNode* left;
    BSTNode* right;
};

// insert karo (your exact insert function)
BSTNode* bstInsert(BSTNode* root, int id, string rec, string dest) {
    if (root == nullptr) {
        BSTNode* newNode = new BSTNode;
        newNode->trackingID  = id;
        newNode->receiverName = rec;
        newNode->destination  = dest;
        newNode->left  = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (id < root->trackingID) {
        root->left  = bstInsert(root->left,  id, rec, dest);
    } else if (id > root->trackingID) {
        root->right = bstInsert(root->right, id, rec, dest);
    }
    return root;
}

// search karo (your exact search function)
bool bstSearch(BSTNode* root, int id) {
    if (root == nullptr) return false;
    if (root->trackingID == id) return true;
    if (id < root->trackingID) return bstSearch(root->left,  id);
    else                        return bstSearch(root->right, id);
}

// inorder — sorted IDs (your exact inorder)
void bstInorder(BSTNode* root) {
    if (root != nullptr) {
        bstInorder(root->left);
        cout << "   ID: " << root->trackingID
             << "  →  " << root->receiverName
             << "  →  " << root->destination << "\n";
        bstInorder(root->right);
    }
}

// preorder — tree structure (your exact preorder)
void bstPreorder(BSTNode* root) {
    if (root != nullptr) {
        cout << "   ID: " << root->trackingID
             << "  →  " << root->receiverName << "\n";
        bstPreorder(root->left);
        bstPreorder(root->right);
    }
}


// ================================================================
//   SECTION 5 — MENU + HELPER FUNCTIONS
// ================================================================

void printLine() {
    cout << "   ══════════════════════════════════════════\n";
}

void printHeader() {
    cout << "\n";
    printLine();
    cout << "   ║    📦  COURIER TRACKING SYSTEM  📦    ║\n";
    cout << "   ║         DSA Project — C++              ║\n";
    printLine();
    cout << "   [1]  Register New Courier\n";
    cout << "   [2]  Update Courier Status\n";
    cout << "   [3]  Track Courier (Full History)\n";
    cout << "   [4]  Search by ID — BST O(log n)\n";
    cout << "   [5]  Display All Couriers\n";
    cout << "   [6]  All Couriers Sorted by ID (BST Inorder)\n";
    cout << "   [7]  BST Preorder View\n";
    cout << "   [8]  Mark as Delivered\n";
    cout << "   [9]  Cancel Courier\n";
    cout << "   [0]  Exit\n";
    printLine();
    cout << "   Enter choice: ";
}


// ================================================================
//   SECTION 6 — MAIN
// ================================================================

int main() {

    // ------- YOUR DATA STRUCTURES INITIALIZED -------
    SinglyLinkedList<Courier*> courierList;  // YOUR linked list
    BSTNode* bstRoot = nullptr;              // YOUR BST root
    // StatusStack is inside each Courier     // YOUR stack

    int  idCounter = 1001;  // auto ID generation
    int  choice;

    // -------- SAMPLE DATA (demo ke liye) --------
    // Courier 1
    Courier* c1 = new Courier(1001, "Ali Raza", "Sara Khan",
                               "Karachi", "2.5 kg", "0300-1234567");
    c1->history.push("Picked Up from Sender",    "Day 1 - 02:00 PM");
    c1->history.push("Arrived at Lahore Hub",    "Day 2 - 10:00 AM");
    c1->history.push("In Transit to Karachi",    "Day 2 - 06:00 PM");
    courierList.insert(c1);
    bstRoot = bstInsert(bstRoot, 1001, "Sara Khan", "Karachi");

    // Courier 2
    Courier* c2 = new Courier(1002, "Bilal Ahmed", "Zara Ali",
                               "Lahore", "0.5 kg", "0311-9876543");
    c2->history.push("Picked Up from Sender",    "Day 1 - 11:00 AM");
    courierList.insert(c2);
    bstRoot = bstInsert(bstRoot, 1002, "Zara Ali", "Lahore");

    // Courier 3
    Courier* c3 = new Courier(1003, "Usman Tariq", "Hira Baig",
                               "Islamabad", "5.0 kg", "0333-5556677");
    c3->history.push("Picked Up from Sender",    "Day 2 - 09:00 AM");
    c3->history.push("Arrived at Pindi Hub",     "Day 2 - 04:00 PM");
    c3->history.push("Out for Delivery",         "Day 3 - 08:00 AM");
    courierList.insert(c3);
    bstRoot = bstInsert(bstRoot, 1003, "Hira Baig", "Islamabad");

    idCounter = 1004;

    // -------- MAIN LOOP --------
    do {
        printHeader();
        cin >> choice;
        cin.ignore();

        // ── 1. Register New Courier ──────────────────────────
        if (choice == 1) {
            string sender, receiver, dest, weight, phone;
            cout << "\n   --- Register New Courier ---\n";
            cout << "   Sender Name   : "; getline(cin, sender);
            cout << "   Receiver Name : "; getline(cin, receiver);
            cout << "   Destination   : "; getline(cin, dest);
            cout << "   Weight (kg)   : "; getline(cin, weight);
            cout << "   Receiver Phone: "; getline(cin, phone);

            Courier* newC = new Courier(idCounter, sender,
                                        receiver, dest, weight, phone);
            courierList.insert(newC);                          // YOUR linked list insert
            bstRoot = bstInsert(bstRoot, idCounter,            // YOUR BST insert
                                receiver, dest);

            cout << "\n   ✓ Courier Registered!\n";
            cout << "   Tracking ID   : " << idCounter << "\n";
            cout << "   Give this ID to sender for tracking.\n";
            idCounter++;

        // ── 2. Update Status ─────────────────────────────────
        } else if (choice == 2) {
            int id;
            string status, time;
            cout << "\n   Enter Tracking ID : "; cin >> id; cin.ignore();
            cout << "   New Status        : "; getline(cin, status);
            cout << "   Date & Time       : "; getline(cin, time);

            Courier* found = courierList.searchByID(id);       // YOUR LL search
            if (found == nullptr) {
                cout << "\n   ✗ Tracking ID " << id << " not found!\n";
            } else {
                found->history.push(status, time);             // YOUR stack push
                cout << "\n   ✓ Status updated for ID " << id << "\n";
                cout << "   Current Status: " << found->history.peekStatus() << "\n";
            }

        // ── 3. Track Courier ─────────────────────────────────
        } else if (choice == 3) {
            int id;
            cout << "\n   Enter Tracking ID : "; cin >> id;

            Courier* found = courierList.searchByID(id);       // YOUR LL search
            if (found == nullptr) {
                cout << "\n   ✗ Invalid Tracking ID!\n";
            } else {
                cout << "\n";
                printLine();
                cout << "   ║       TRACKING DETAILS                  ║\n";
                printLine();
                cout << "   Tracking ID  : " << found->trackingID   << "\n";
                cout << "   Sender       : " << found->senderName   << "\n";
                cout << "   Receiver     : " << found->receiverName << "\n";
                cout << "   Destination  : " << found->destination  << "\n";
                cout << "   Weight       : " << found->weight       << "\n";
                cout << "   Phone        : " << found->phone        << "\n";
                cout << "   Current      : " << found->history.peekStatus() << "\n";
                cout << "\n   --- Full History (Latest First) ---\n";
                found->history.displayHistory();               // YOUR stack display
                printLine();
            }

        // ── 4. BST Search ─────────────────────────────────────
        } else if (choice == 4) {
            int id;
            cout << "\n   Enter Tracking ID (BST Search): "; cin >> id;

            bool found = bstSearch(bstRoot, id);               // YOUR BST search
            if (!found) {
                cout << "\n   ✗ ID " << id << " not found in BST!\n";
            } else {
                cout << "\n   ✓ ID " << id << " EXISTS in system (BST O(log n))\n";
                // full details LL se lo
                Courier* c = courierList.searchByID(id);
                if (c != nullptr) {
                    cout << "   Receiver    : " << c->receiverName << "\n";
                    cout << "   Destination : " << c->destination  << "\n";
                    cout << "   Status      : " << c->history.peekStatus() << "\n";
                }
            }

        // ── 5. Display All ────────────────────────────────────
        } else if (choice == 5) {
            cout << "\n";
            printLine();
            cout << "   ║         ALL COURIERS                    ║\n";
            printLine();
            courierList.display();                             // YOUR LL display

        // ── 6. BST Inorder (Sorted) ───────────────────────────
        } else if (choice == 6) {
            cout << "\n   --- All Couriers Sorted by ID (BST Inorder) ---\n";
            bstInorder(bstRoot);                               // YOUR BST inorder

        // ── 7. BST Preorder ───────────────────────────────────
        } else if (choice == 7) {
            cout << "\n   --- BST Preorder View ---\n";
            bstPreorder(bstRoot);                              // YOUR BST preorder

        // ── 8. Mark Delivered ─────────────────────────────────
        } else if (choice == 8) {
            int id;
            cout << "\n   Enter Tracking ID to mark Delivered: "; cin >> id;

            Courier* found = courierList.searchByID(id);
            if (found == nullptr) {
                cout << "\n   ✗ ID not found!\n";
            } else {
                found->history.push("DELIVERED ✓", "Final");  // YOUR stack push
                cout << "\n   ✓ Courier " << id << " marked as DELIVERED!\n";
                cout << "   Receiver: " << found->receiverName << "\n";
                // list se remove karo
                courierList.deleteByID(id);                    // YOUR LL delete
                cout << "   Removed from active list.\n";
            }

        // ── 9. Cancel ─────────────────────────────────────────
        } else if (choice == 9) {
            int id;
            cout << "\n   Enter Tracking ID to Cancel: "; cin >> id;

            Courier* found = courierList.searchByID(id);
            if (found == nullptr) {
                cout << "\n   ✗ ID not found!\n";
            } else {
                found->history.push("CANCELLED ✗", "Final");  // YOUR stack push
                cout << "\n   ✓ Courier " << id << " CANCELLED.\n";
                courierList.deleteByID(id);                    // YOUR LL delete
            }

        // ── 0. Exit ───────────────────────────────────────────
        } else if (choice == 0) {
            cout << "\n";
            printLine();
            cout << "   ║   Thank you for using Courier System!  ║\n";
            printLine();
            cout << "\n";

        } else {
            cout << "\n   [!] Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}