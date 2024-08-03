#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <string>
#include "library.hpp"
#include "book.hpp"
#include "user.hpp"


/**
 * @brief Constructs a Library object.
 * 
 * Initializes an empty library.
*/
Library::Library()
{

}

/**
 * @brief Destructs a Library object.
 * 
 * Cleans up resources and destroys the library.
*/
Library::~Library()
{   
    // Clears the unordered_map containing books
    users.clear();
    // Clears the unordered_map containing users
    books.clear();
}

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
add_handling_t Library::AddNewBookToLibrary(Book *book)
{
    // Check if the book with the same ISBN is already in the library
    if(books.count(book->GetBookNumber()))
    {
        // ISBN already exists in the library, return ALREADY_TAKEN
        return ALREADY_TAKEN;
    }
    else
    {   
        // Insert the new book into the library's collection
        books[book->GetBookNumber()] = shared_ptr<Book>(book);

        // Book added successfully, return ADDED_SUCCESSFULLY
        return ADDED_SUCCESSFULLY;
    }   
}

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
remove_handling_t Library::RemoveBookFromLibrary(const string &ISBN)
{
    // Check if the book with the specified ISBN exists in the library
    if(books.count(ISBN))
    {
        // Remove the book from the library's collection
        books.erase(ISBN);
        // Book removed successfully, return REMOVED
        return REMOVED;       
    }
    else
    {
        // Book with the specified ISBN does not exist, return NOT_EXCIST
        return NOT_EXCIST;        
    }
}

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
add_handling_t Library::RegisterNewUser(User *new_user)
{
    // Check if the user with the same ID is already registered
    if(users.count(new_user->GetUserId()))
    {
        // User ID already exists in the library, return ALREADY_TAKEN
        return ALREADY_TAKEN;
    }
    else
    {
        // Register the new user in the library's records
        users[new_user->GetUserId()] = unique_ptr<User> (new_user);
        // User added successfully, return ADDED_SUCCESSFULLY
        return ADDED_SUCCESSFULLY;
    }
}

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
remove_handling_t Library::RemoveUserFromLibrary(const int &id)
{
    // Check if the user with the specified ID exists in the library
    if(users.count(id))
    {
        // Remove the user from the library's records
        users.erase(id);

        // User removed successfully, return REMOVED
        return REMOVED;
    }
    else
    {
        // User with the specified ID does not exist, return NOT_EXCIST
        return NOT_EXCIST;
    }
}

/**
 * @brief Displays all books currently in the library.
 * 
 * This method prints out details of all the books in the library's collection.
*/
void Library::DisplayAllBooks()
{
    // Iterator to traverse the unordered_map of books
    auto it = books.begin();
    
    // Counter for displaying book numbers
    int number = 1;

    // Iterate through all books in the library
    for(; it != books.end(); it++)
    { 
        // Display separator and book number
        cout << "==============================================\n";
        cout << "the book number "<< number<< " details\n";
        cout << "==============================================\n";
        
        // Display book details
        cout << "book_ISBN: " << it->first << "\n" << "book_name: " << it->second->GetBookName() 
        << "\n" << "book_category: " << it->second->GetBookGener()<< "\n" << "book_auther: " << it->second->GetBookAuthor()
        << "\n" << "book_availability: " << it->second->GetBookAvailability() << "\n"; 
        
        // Increment book counter
        number++;
        
        // Display separator
        cout << "==============================================\n";
    }
}

/**
 * @brief Displays all users currently registered in the library.
 * 
 * This method prints out details of all users registered in the library.
*/
void Library::DisplayAllUsers()
{
    // Iterator to traverse the unordered_map of users
   auto it = users.begin();
    
    // Counter for displaying user numbers
    int number = 1;

    // Iterate through all users in the library
    for(; it != users.end(); it++)
    { 
        // Display separator and user number
        cout << "==============================================\n";
        cout << "the user number "<< number<< " details\n";
        cout << "==============================================\n";
        
        // Display user details
        cout << "user_id: "<< it->first << "\n" << "user_name: " << it->second->GetUserName() << "\n"; 
        
        // Increment user counter
        number++;

        // Display separator
        cout << "==============================================\n";
    } 
}

/**
 * @brief Allows a user to borrow a book from the library.
 * 
 * This method facilitates the borrowing of a book by a user. It updates the library's records
 * to reflect that the book is now borrowed by the user.
 * 
 * @param user_id The ID of the user borrowing the book.
 * @param temp_ISBN The ISBN of the book being borrowed.
*/
void Library::UserBorrowBook(const int &user_id ,const string &temp_ISBN)
{
    // Check if the user with the specified ID exists
    if(users.count(user_id))
    {
        // Check if the book with the specified ISBN exists
        if(books.count(temp_ISBN))
        {
            // Get the book and user pointers
            auto it = books[temp_ISBN];
            auto& it_2 = users[user_id];

            // Attempt to borrow the book
            Ret_val_t ret = it_2->UserBorrowBook(it);
            
            // Check if the borrowing was successful
            if(ret == TRUE)
            {
                cout << "the user "<<it_2->GetUserName()<<" borrowed the book "
                <<it->GetBookName()<< " successuflly!\n";
            } 
            else
            {
                cout << "Fail!! This book is already borrowed and not available\n";
            }
        }
        else
        {
            // Book with the specified ISBN does not exist
            cout << "Failed!! There is no book with that serial in the library\n";
        }
    }
    else
    {
        // User with the specified ID does not exist
        cout << "invalid id!! this user isn't registed in the library\n";
    }
}

/**
 * @brief Allows a user to return a book to the library.
 * 
 * This method facilitates the return of a book by a user. It updates the library's records
 * to reflect that the book has been returned.
 * 
 * @param user_id The ID of the user returning the book.
 * @param temp_ISBN The ISBN of the book being returned.
*/
void Library::UserReturnBook(const int &user_id ,const string &temp_ISBN)
{
    // Check if the user with the specified ID exists
    if(users.count(user_id))
    {
        // Check if the book with the specified ISBN exists
        if(books.count(temp_ISBN))
        {
            // Get the book and user pointers
            auto it = books[temp_ISBN];
            auto& it_2 = users[user_id];

            // Attempt to return the book
            Ret_val_t ret = it_2->UserReturnBook(it); 

            // Check if the return was successful
            if(ret == TRUE)
            {
                cout << "the user "<<it_2->GetUserName()<<" returned the borrowed book "<<it->GetBookName()<< " successuflly!\n";
            }
            else
            {
                cout << "Sorry!! the user: "<<it_2->GetUserName()<< " doesn't even borrow the book "
                << it->GetBookName() << "\n";
            }

        }
        else
        {
            // Book with the specified ISBN does not exist
            cout << "Failed!! There is no book with that serial in the library\n";
        }
    }
    else
    {
        // User with the specified ID does not exist
        cout << "invalid id!! this user isn't registed in the library\n";
    }
}



