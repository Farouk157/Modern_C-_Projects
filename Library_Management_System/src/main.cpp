#include <iostream>
#include <string>
#include <vector>
#include "library.hpp"
#include "user.hpp"
#include "book.hpp"


using namespace std;

/**
 * @brief Main function for the Library Management System application.
 * 
 * This function demonstrates the functionality of the `Library` class by providing a command-line 
 * interface for interacting with the library system. Users can add, remove, register, display, 
 * borrow, and return books and users through this interface.
 * 
 * @return int Exit status of the application (0 for success).
 */

int main(void)
{
    // Creates an instance of the Library class to manage the books and users.
    Library library;

    // Creating instances of Book with sample data.
    Book *b_1 = new Book("LinearAlgebra", "Dr. yasser", "Mathematics", "123qwe");
    // Book *b_2 = new Book("Calculus", "Dr. Mohamed", "Mathematics", "asd123");
    Book *b_3 = new Book("Geometry", "Dr. bryan", "Mathematics", "173-813");
    Book *b_4 = new Book("Electromagnetism", "Dr. Ahmed", "Physics", "482-423");
    Book *b_5 = new Book("Anatomy", "Dr. magdy", "Medicine", "213-83");
    // Book *b_6 = new Book("The law ", "Dr. Peter", "Law", "222-33");
    // Book *b_7 = new Book("Football", "Dr. naser", "Sports", "11-255");

    // Adding books to the library.
    library.AddNewBookToLibrary(b_1);
    // library.AddNewBookToLibrary(b_2);
    library.AddNewBookToLibrary(b_3);
    library.AddNewBookToLibrary(b_4);
    library.AddNewBookToLibrary(b_5);
    // library.AddNewBookToLibrary(b_6);
    // library.AddNewBookToLibrary(b_7);

    
    bool run = true; // Flag to control the main loop of the application.
    int option = 0;  // Variable to store the user's menu choice.

    // Variables to store book details.
    string b_name, b_author, b_gener, b_ISBN;

    // Variable to store user details.
    string u_name; 
    // Variable to store user ID.
    int u_id;

    // Main loop of the application.
    while(run)
    {
        // Display the menu options to the user.
        cout << "------------------------------------------\n";
        cout << "Welcome to the Library Management System\n";
        cout << "------------------------------------------\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book\n";
        cout << "3. Register a new user\n";
        cout << "4. Remove a user\n";
        cout << "5. Display all books\n";
        cout << "6. Display all users\n";
        cout << "7. Borrow a book\n";
        cout << "8. Return a book\n";
        cout << "9. Search for a book\n";
        cout << "0. Exit\n";
        cout << "------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> option; // Read the user's choice.


        // Perform actions based on the user's choice.
        switch(option)
        {
            case 1:  // Add a new book to the library.
            {
                cout << "enter the book name: ";
                cin  >> b_name;
                cout << "enter the book author: ";
                cin  >> b_author;
                cout << "enter the book category: ";
                cin  >> b_gener;
                cout << "enter the book ISBN: ";
                cin  >> b_ISBN; 

                Book *b_ptr = new Book(b_name, b_author, b_gener, b_ISBN); 

                add_handling_t ret_val = library.AddNewBookToLibrary(b_ptr);

                if(ret_val == ADDED_SUCCESSFULLY)
                {
                    cout << "The book is added successfully to the library!\n";
                }
                else
                {
                    cout << "The book is already exist with the same serial number\n";
                }
                break;
            }
            case 2: // Remove a book from the library.
            {
                cout << "enter the serial number of the book to remove: ";
                cin >> b_ISBN;
                remove_handling_t ret_val = library.RemoveBookFromLibrary(b_ISBN);
                if(ret_val == REMOVED)
                {
                    cout << "The book is removed successfully!\n";
                }
                else
                {
                    cout << "the serial number of the book is not even exist\n";
                }
                break;
            }
            case 3: // Register a new user in the library.
            {
                cout << "enter the user name: ";
                cin >> u_name;
                cout << "enter the user id: ";
                cin >> u_id;

                User *u_ptr = new User(u_name, u_id);
                
                add_handling_t ret_val = library.RegisterNewUser(u_ptr);
                if(ret_val == ADDED_SUCCESSFULLY)
                {
                    cout << "The user is registered successfully!\n";
                }
                else
                {
                    cout << "Sorry this id is already taken please choose another one \n";
                }
                break;
            }
            case 4: // Remove a user from the library.
            {
                cout << "enter the user id: ";
                cin >> u_id;
                remove_handling_t ret_val = library.RemoveUserFromLibrary(u_id);
                if(ret_val == REMOVED)
                {
                    cout << "The user is removed successfully!\n";
                }
                else
                {
                    cout << "this user id is not registered\n";
                }               
                break;
            }
           case 5: // Display all books in the library.
            {
                library.DisplayAllBooks();
                break;
            } 
            case 6: // Display all users registered in the library.
            {
                library.DisplayAllUsers();
                break;
            }
            case 7: // Borrow a book from the library.
            {
                cout << "enter the user id: ";
                cin  >> u_id;
                cout << "enter the book serial number: ";
                cin  >> b_ISBN;

                library.UserBorrowBook(u_id, b_ISBN);                 
                break;
            }
            case 8: // Return a book to the library.
            {
                cout << "enter the user id: ";
                cin  >> u_id;
                cout << "enter the book serial number: ";
                cin  >> b_ISBN;

                library.UserReturnBook(u_id, b_ISBN);
                break;
            }
            case 9:
            {
                break;
            } 
            case 0: // Exit the application.
            {
                cout << "The system is turened off!\n";
                run = false; // Set the flag to false to exit the main loop.
                break;
            }    
            default:
                // Handle invalid menu choices.
                break;                
        }
    }

    // Clean up dynamically allocated Book objects.
    delete b_1;
    // delete b_2;
    delete b_3;
    delete b_4;
    delete b_5;
    // delete b_6;
    // delete b_7;

    // Return 0 to indicate successful completion of the application.
    return 0;
}