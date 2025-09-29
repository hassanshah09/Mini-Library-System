# Mini-Library-System
This project is a Mini Library Management System in C++. It demonstrates the use of dynamic arrays, stacks, pointers, and 2D arrays through a simple menu-driven program where users can add, delete, undo, search, and display books.

# 📚 Mini Library Management System (C++)

This is a simple **Mini Library project** written in **C++** that demonstrates the use of:

- **Dynamic Arrays** → Automatically resize when storage is full.  
- **Stack (Undo Feature)** → Allows restoring the last deleted book.  
- **Pointers** → Used for accessing array elements.  
- **2D Array** → Used to display all books in a tabular format.  
- **Menu-Driven Program** → User interacts via numbered options.

---

## 🚀 Features
1. **Add Book**  
   - Enter book ID, title, and author.  
   - If the array is full, capacity doubles automatically.  

2. **Delete Book**  
   - Remove a book by entering its ID.  
   - The deleted book’s ID is stored in a stack for undo functionality.  

3. **Undo Delete**  
   - Restores the most recently deleted book using the stack.  
   - Title and author are restored as `"Restored"` (basic version).  

4. **Search Book**  
   - Find a book by its ID using linear search.  

5. **Display All Books**  
   - Shows all stored books in a tabular format using a 2D array.  

6. **Exit Program**  
   - Cleanly terminates the program and frees dynamic memory.

---

## 🛠️ How It Works
- **Dynamic Array:**  
  Starts with a capacity of `2`. When full, the size is doubled (`2 → 4 → 8 → ...`) and old data is copied into the new array.  

- **Stack:**  
  Keeps track of deleted book IDs. Undo works on the principle of **Last In, First Out (LIFO)**.  

- **Pointers:**  
  Demonstrates pointer-based access like `*(ids + i)` instead of `ids[i]`.  

- **2D Array:**  
  Used to prepare the tabular display of books.

---

## 📷 Example Run

