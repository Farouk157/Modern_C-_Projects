#include <iostream>
#include <string>
#include "user.hpp"
#include <vector> 
#include <memory>
#include "book.hpp"

using namespace std;

/**
 * @brief Default constructor for the User class.
 * 
 * Initializes an empty User object with default values.
*/ 
User::User()
{
    /* nothing */
}

/**
 * @brief Parameterized constructor for the User class.
 * 
 * Initializes a User object with the provided name and ID.
 * 
 * @param name Reference to the user's name.
 * @param id Reference to the user's ID.
*/
User::User(string &name, int &id)
{
    // Set the user's name to the provided name.
    user_name = name;
    // Set the user's ID to the provided ID.
    user_id = id;
}

/**
 * @brief Destructor for the User class.
 * 
 * Cleans up any resources associated with the User object.
*/
User::~User()
{   
    // Clear the list of borrowed books
    books_borrowed.clear();
}

/**
 * @brief Sets the user's name.
 * 
 * @param name The new name of the user.
*/
void User::SetUserName(const string &name)
{
    // Assign the new name to the user_name member variable.
    user_name = name;
}

/**
 * @brief Sets the user's ID.
 * 
 * @param id The new ID for the user.
*/
void User::SetUserId(const int &id)
{
    // Assign the new ID to the user_id member variable.
    user_id = id;
}

/**
 * @brief Gets the user's name.
 * 
 * @return The name of the user.
*/
string User::GetUserName()
{
    // Return the current value of the user_name member variable.
    return user_name;
}

/**
 * @brief Gets the user's ID.
 * 
 * @return The ID of the user.
*/
int User::GetUserId()
{
    // Return the current value of the user_id member variable.
    return user_id;
}

/**
 * @brief Allows the user to borrow a book.
 * 
 * Adds the specified book to the list of borrowed books if the book is not already
 * borrowed by the user.
 * 
 * @param book Shared pointer to the book to be borrowed.
 * @return Ret_val_t Enumeration indicating the result of the operation.
*/
Ret_val_t User::UserBorrowBook(shared_ptr<Book> book)
{
    // Check if the book is available for borrowing.
    if(book->GetBookAvailability())
    {
        // Set availability to false since the book will be borrowed.
        bool avail = false;
        // Add the book to the list of borrowed books.
        books_borrowed.push_back(book);
        // Update the book's availability status.
        book->SetBookAvailability(avail);
        // Return TRUE to indicate successful borrowing.
        return TRUE;
    }
    else
    {
        // Return FALSE to indicate that the book could not be borrowed.
        return FALSE;
    }
    
}

/**
 * @brief Allows the user to return a book.
 * 
 * Removes the specified book from the list of borrowed books if the book is currently
 * borrowed by the user.
 * 
 * @param book Shared pointer to the book to be returned.
 * @return Ret_val_t Enumeration indicating the result of the operation.
*/
Ret_val_t User::UserReturnBook(shared_ptr<Book> book)
{
    // Initialize the result to FALSE, indicating failure by default.
    Ret_val_t temp = FALSE;

    //< Iterator to traverse the list of borrowed books.
    vector<shared_ptr<Book>>::iterator it = books_borrowed.begin();
     // Check if the book is in the list of borrowed books.
    for(; it!= books_borrowed.end(); it++)
    {   
       
        ///< Check if the book is in the list of borrowed books  
        if(*it == book)
        {
             // Set availability to true since the book will be returned.
            bool avail = true;
            //< Remove the book from the list of borrowed books.
            books_borrowed.erase(it);
            ///< Update the book's availability status.
            book->SetBookAvailability(avail);
            ///< Set the result to TRUE, indicating successful return.
            temp = TRUE;
            ///< Exit the loop as the book has been found and removed.
            break;    
        }
    }
     ///< Return the result of the operation (TRUE or FALSE).
    return temp;
}

/**
 * @brief Gets the list of books borrowed by the user.
 * 
 * @return A vector of shared pointers to the books borrowed by the user.
*/
vector<shared_ptr<Book>> User::GetBorrowedBooks()
{
     ///< Return the list of borrowed books.
    return books_borrowed;
}