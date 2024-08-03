#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_

#include <unordered_map>
#include <memory>
#include "book.hpp"
#include "user.hpp"

/**
 * @brief Enumeration for handling the result of adding a book to the library.
 */
typedef enum
{
    ALREADY_TAKEN,          /* Indicates that the book is already present in the library. */
    ADDED_SUCCESSFULLY      /* Indicates that the book was added successfully. */
}add_handling_t;

/**
 * @brief Enumeration for handling the result of removing a book or user from the library.
 */
typedef enum
{
    NOT_EXCIST,
    EXCIT,
    REMOVED
}remove_handling_t;

// Use the standard namespace for convenience
using namespace std;

/**
 * @brief A class representing a library system.
 * 
 * The Library class manages a collection of books and users. It provides functionalities 
 * for adding, removing, searching, and displaying books and users, as well as handling 
 * book borrowing and returning operations.
 */

class Library
{
    private: 
        /* A hash map that stores books with their ISBN as keys. */
        unordered_map<string, shared_ptr<Book>> books;

        /* A hash map that stores users with their ID as keys. */
        unordered_map<int, unique_ptr<User>> users;     

    public: 
        /**
         * @brief Constructs a Library object.
         * 
         * Initializes an empty library.
        */
        Library();

        /**
         * @brief Destructs a Library object.
         * 
         * Cleans up resources and destroys the library.
        */
        ~Library();

        /**
         * @brief Adds a new book to the library.
         * 
         * This method attempts to add a book to the library's collection. If the book is already
         * present in the library, it returns ALREADY_TAKEN. If the book is added successfully,
         * it returns ADDED_SUCCESSFULLY.
         * 
         * @param book Pointer to the Book object to be added.
         * @return add_handling_t Enumeration value indicating the result of the operation.
        */
        add_handling_t AddNewBookToLibrary(Book *book);

        /**
         * @brief Removes a book from the library using its ISBN.
         * 
         * This method attempts to remove a book from the library's collection based on its ISBN.
         * If the book does not exist, it returns NOT_EXCIST. If the book exists but could not be removed,
         * it returns EXCIT. If the book is successfully removed, it returns REMOVED.
         * 
         * @param ISBN The ISBN of the book to be removed.
         * @return remove_handling_t Enumeration value indicating the result of the operation.
        */
        remove_handling_t RemoveBookFromLibrary(const string &ISBN);

        /**
         * @brief Registers a new user in the library.
         * 
         * This method attempts to register a new user. If the user is already registered,
         * it returns ALREADY_TAKEN. If the user is successfully registered, it returns
         * ADDED_SUCCESSFULLY.
         * 
         * @param new_user Pointer to the User object to be registered.
         * @return add_handling_t Enumeration value indicating the result of the operation.
        */
        add_handling_t RegisterNewUser(User *new_user);

        /**
         * @brief Removes a user from the library using their ID.
         * 
         * This method attempts to remove a user from the library's records based on their ID.
         * If the user does not exist, it returns NOT_EXCIST. If the user exists but could not
         * be removed, it returns EXCIT. If the user is successfully removed, it returns REMOVED.
         * 
         * @param id The ID of the user to be removed.
         * @return remove_handling_t Enumeration value indicating the result of the operation.
        */
        remove_handling_t RemoveUserFromLibrary(const int &id);

        /**
         * @brief Displays all books currently in the library.
         * 
         * This method prints out details of all the books in the library's collection.
        */
        void DisplayAllBooks();

        /**
         * @brief Displays all users currently registered in the library.
         * 
         * This method prints out details of all users registered in the library.
        */
        void DisplayAllUsers();

        /**
         * @brief Allows a user to borrow a book from the library.
         * 
         * This method facilitates the borrowing of a book by a user. It updates the library's records
         * to reflect that the book is now borrowed by the user.
         * 
         * @param user_id The ID of the user borrowing the book.
         * @param temp_ISBN The ISBN of the book being borrowed.
        */
        void UserBorrowBook(const int &user_id ,const string &temp_ISBN);

        /**
         * @brief Allows a user to return a book to the library.
         * 
         * This method facilitates the return of a book by a user. It updates the library's records
         * to reflect that the book has been returned.
         * 
         * @param user_id The ID of the user returning the book.
         * @param temp_ISBN The ISBN of the book being returned.
        */
        void UserReturnBook(const int &user_id ,const string &temp_ISBN);
    
        Book *SearchForBook(string title);
        // Book *SearchForBook(string author);
        // Book *SearchForBook(string genre);
};




#endif