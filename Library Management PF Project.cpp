#include <iostream>
#include <string>
using namespace std;


const int MAX_BOOKS = 100;

struct Book {
    string title;
    string author;
    bool isIssued;
};
int main() {
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (true) {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. View All Books" << endl;
        cout << "3. Issue a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (bookCount < MAX_BOOKS) {
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, library[bookCount].title);
                cout << "Enter author name: ";
                getline(cin, library[bookCount].author);
                library[bookCount].isIssued = false;
                bookCount++;
                cout << "Book added successfully!" << endl;
            } else {
                cout << "Library is full! Cannot add more books." << endl;
            }
        } else if (choice == 2) {
            if (bookCount == 0) {
                cout << "No books available in the library." << endl;
            } else {
                cout << "\nList of Books:" << endl;
                for (int i = 0; i < bookCount; i++) {
                    cout << i + 1 << ". " << library[i].title << " by " << library[i].author;
                    if (library[i].isIssued) {
                        cout << " (Issued)";
                    }
                    cout << endl;
                }
            }
        } else if (choice == 3) {
            int bookNumber;
            cout << "Enter the book number to issue: ";
            cin >> bookNumber;

            if (bookNumber > 0 && bookNumber <= bookCount) {
                if (!library[bookNumber - 1].isIssued) {
                    library[bookNumber - 1].isIssued = true;
                    cout << "Book issued successfully!" << endl;
                } else {
                    cout << "This book is already issued." << endl;
                }
            } else {
                cout << "Invalid book number." << endl;
            }
        } else if (choice == 4) {
            int bookNumber;
            cout << "Enter the book number to return: ";
            cin >> bookNumber;

            if (bookNumber > 0 && bookNumber <= bookCount) {
                if (library[bookNumber - 1].isIssued) {
                    library[bookNumber - 1].isIssued = false;
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "This book was not issued." << endl;
                }
            } else {
                cout << "Invalid book number." << endl;
            }
        } else if (choice == 5) {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}