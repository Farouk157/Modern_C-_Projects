#ifndef _USER_HPP_ 
#define _USER_HPP_

#include <string>
#include <vector>
#include <memory>
#include "book.hpp"

// Use the standard namespace for convenience
using namespace std;


// Enumeration to represent boolean return values
typedef enum
{
    // Represents a failure or false condition
    FALSE = 0,
    // Represents a success or true condition
    TRUE
}Ret_val_t;


/**
 * @brief Represents a user in the library system.
 * 
 * The User class manages user information, including their name, ID, and a list of books
 * they have borrowed. It provides methods to set and get user details and manage book borrowing
 * and returning.
*/
class User
{
    private: 
        // The name of the user.
        string user_name; 
        // The unique identifier for the user.
        int user_id;
        // List of books borrowed by the user.
        vector<shared_ptr<Book>> books_borrowed;

    public:
        /**
         * @brief Default constructor for the User class.
         * 
         * Initializes an empty User object with default values.
        */ 
        User();
        
        /**
         * @brief Parameterized constructor for the User class.
         * 
         * Initializes a User object with the provided name and ID.
         * 
         * @param name Reference to the user's name.
         * @param id Reference to the user's ID.
         */
        User(string &name, int &id);

        /**
         * @brief Destructor for the User class.
         * 
         * Cleans up any resources associated with the User object.
         */
        ~User();

        /**
         * @brief Sets the user's name.
         * 
         * @param name The new name of the user.
         */
        void SetUserName(const string &name);

        /**
         * @brief Sets the user's ID.
         * 
         * @param id The new ID for the user.
         */
        void SetUserId(const int &id);

        /**
         * @brief Gets the user's name.
         * 
         * @return The name of the user.
        */
        string GetUserName();

        /**
         * @brief Gets the user's ID.
         * 
         * @return The ID of the user.
        */
        int GetUserId();

        /**
         * @brief Allows the user to borrow a book.
         * 
         * Adds the specified book to the list of borrowed books if the book is not already
         * borrowed by the user.
         * 
         * @param book Shared pointer to the book to be borrowed.
         * @return Ret_val_t Enumeration indicating the result of the operation.
        */
        Ret_val_t UserBorrowBook(shared_ptr<Book> book);

        /**
         * @brief Allows the user to return a book.
         * 
         * Removes the specified book from the list of borrowed books if the book is currently
         * borrowed by the user.
         * 
         * @param book Shared pointer to the book to be returned.
         * @return Ret_val_t Enumeration indicating the result of the operation.
        */
        Ret_val_t UserReturnBook(shared_ptr<Book> book);

        /**
         * @brief Gets the list of books borrowed by the user.
         * 
         * @return A vector of shared pointers to the books borrowed by the user.
        */
        vector<shared_ptr<Book>> GetBorrowedBooks();   
};





#endif