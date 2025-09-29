#include <iostream>
#include <string>
using namespace std;

int main() {
    int capacity = 2;                  // initial dynamic array size
    int size = 0;                      // number of books
    int *ids = new int[capacity];      // dynamic array for IDs
    string *titles = new string[capacity];
    string *authors = new string[capacity];

    int deleted[100];                  // stack for deleted IDs
    int top = -1;

    while (true) {
        cout << "\n--- Mini Library Menu ---\n";
        cout << "1. Add Book\n2. Delete Book\n3. Undo Delete\n4. Search Book\n5. Display All\n0. Exit\nChoice: ";
        int choice;
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) { // Add Book
            if (size == capacity) { // resize
                capacity *= 2;
                int *newIds = new int[capacity];
                string *newTitles = new string[capacity];
                string *newAuthors = new string[capacity];
                for (int i = 0; i < size; i++) {
                    newIds[i] = ids[i];
                    newTitles[i] = titles[i];
                    newAuthors[i] = authors[i];
                }
                delete[] ids; delete[] titles; delete[] authors;
                ids = newIds; titles = newTitles; authors = newAuthors;
            }
            cout << "Enter ID: "; cin >> ids[size];
            cin.ignore();
            cout << "Enter Title: "; getline(cin, titles[size]);
            cout << "Enter Author: "; getline(cin, authors[size]);
            size++;
            cout << "Book added.\n";
        }
        else if (choice == 2) { // Delete Book
            int id; cout << "Enter ID to delete: ";
             cin >> id;
            int pos = -1;
            for (int i = 0; i < size; i++) 
            if (ids[i] == id) 
                pos = i;
            if (pos == -1)
                 cout << "Not found.\n";
            else {
                deleted[++top] = id; // push onto stack
                for (int i = pos; i < size - 1; i++) {
                    ids[i] = ids[i+1];
                    titles[i] = titles[i+1];
                    authors[i] = authors[i+1];
                }
                size--;
                cout << "Book deleted.\n";
            }
        }
        else if (choice == 3) { // Undo Delete
            if (top == -1) cout << "Nothing to undo.\n";
            else {
                int id = deleted[top--]; // pop
                if (size == capacity) { // resize
                    capacity *= 2;
                    int *newIds = new int[capacity];
                    string *newTitles = new string[capacity];
                    string *newAuthors = new string[capacity];
                    for (int i = 0; i < size; i++) {
                        newIds[i] = ids[i];
                        newTitles[i] = titles[i];
                        newAuthors[i] = authors[i];
                    }
                    delete[] ids; delete[] titles; delete[] authors;
                    ids = newIds; titles = newTitles; authors = newAuthors;
                }
                ids[size] = id;
                titles[size] = "Restored";
                authors[size] = "Restored";
                size++;
                cout << "Undo successful.\n";
            }
        }
        else if (choice == 4) { // Search
            int id; cout << "Enter ID to search: "; cin >> id;
            bool found = false;
            for (int i = 0; i < size; i++) {
                if (*(ids + i) == id) { // pointer usage
                    cout << "Found: " << ids[i] << " - " << titles[i] << " by " << authors[i] << "\n";
                    found = true;
                }
            }
            if (!found) cout << "Not found.\n";
        }
        else if (choice == 5) { // Display All
            if (size == 0) cout << "No books.\n";
            else {
                string table[100][3]; // 2D array
                for (int i = 0; i < size; i++) {
                    table[i][0] = to_string(ids[i]);
                    table[i][1] = titles[i];
                    table[i][2] = authors[i];
                }
                cout << "ID\tTitle\t\tAuthor\n";
                for (int i = 0; i < size; i++) {
                    cout << table[i][0] << "\t" << table[i][1] << "\t" << table[i][2] << "\n";
                }
            }
        }
        else cout << "Invalid option.\n";
    }

    delete[] ids;
    delete[] titles;
    delete[] authors;
    return 0;
}
