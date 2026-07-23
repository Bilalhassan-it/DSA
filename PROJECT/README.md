# 📦 Courier Tracking System — DSA Project (C++)

A console-based Courier Tracking System built in C++ as part of my Data Structures & Algorithms coursework. It manages courier registration, status updates, delivery tracking, and fast searching using three core data structures implemented from scratch.

---

## 🧠 Data Structures Used

| Data Structure          | Purpose                                            | Reused From                          |
|--------------------------|-----------------------------------------------------|----------------------------------------|
| **Singly Linked List** (`SinglyLinkedList<T>`) | Stores all courier records (insert, search, delete by ID) | Adapted from my earlier work in `Linked List/` folder |
| **Stack** (array-based `StatusStack`)          | Tracks each courier's status history (LIFO — latest status shown first) | Adapted from my earlier work in `STACK/` folder |
| **Binary Search Tree** (`CourierBST`)          | Enables fast **O(log n)** search by Tracking ID, plus sorted (inorder) listing | New implementation for this project |

The Linked List and Stack logic build on the same patterns I practiced in the standalone `Linked List` and `STACK` folders of this repo — here they're combined into a single object-oriented, template-based system (`SinglyLinkedList<Courier>`) instead of storing plain integers.

---

## ✨ Features

1. **Register New Courier** — add sender, receiver, destination, and weight; auto-generates a Tracking ID  
2. **Update Courier Status** — pushes a new status + timestamp onto that courier's history stack  
3. **Track Courier** — shows full status history (latest first) using the stack  
4. **Search by ID (BST)** — fast lookup of receiver & destination via Binary Search Tree  
5. **Display All Couriers** — lists every courier currently in the system (Linked List traversal)  
6. **Display Sorted (BST Inorder)** — shows all Tracking IDs in sorted order  
7. **Mark as Delivered** — logs final status and removes courier from active list  
8. **Cancel Courier** — logs cancellation and removes courier from active list  

Comes preloaded with 3 sample couriers (IDs `1001`, `1002`, `1003`) for quick testing.

---

## 🛠️ How to Run

### Requirements
- A C++ compiler (e.g. **g++** / MinGW)
- Terminal / VS Code

### Steps

```bash
# 1. Clone the repo (if not already)
git clone https://github.com/Bilalhassan-it/DSA.git
cd DSA

# 2. Navigate to the project folder
cd "PROJECT/Courier Tracking System"   # or wherever the .cpp file is placed

# 3. Compile
g++ courier.cpp -o courier.exe

# 4. Run
./courier.exe        # Linux/Mac
.\courier.exe         # Windows PowerShell
```

Once running, use the on-screen menu (1–9) to register couriers, update statuses, track shipments, and search by ID.

---

## 📂 Project Structure