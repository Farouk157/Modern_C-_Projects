#include <iostream>
#include <vector> 
#include <utility>
#include <string>
#include <unordered_map>
#include "book.hpp"

using namespace std;


/**
 * @brief Default constructor for the Book class.
 * 
 * Initializes a Book object with default values.
*/
Book::Book()
{   
    // Sets the availability status of the book to true by default.
    availability = true;
}

/**
 * @brief Parameterized constructor for the Book class.
 * 
 * Initializes a Book object with the specified title, author, genre, and ISBN.
 * 
 * @param title The title of the book.
 * @param author The author of the book.
 * @param gener The genre of the book. (Note: Typo in "gener" should be "genre")
 * @param ISBN The ISBN number of the book.
*/
Book::Book(const string &title,const string &author,const string &gener,const string &ISBN)
{
    // Sets the book title to the value provided by the parameter.
    book_title = title;
    // Sets the book author to the value provided by the parameter.
    book_author = author;
    // Sets the book genre to the value provided by the parameter.
    book_gener = gener;
    // Sets the book ISBN to the value provided by the parameter.
    book_ISBN = ISBN;
    // Sets the availability status of the book to true by default.
    availability = true;
}

/**
 * @brief Destructor for the Book class.
 * 
 * Cleans up any resources used by the Book object.
*/
Book::~Book()
{
    // Destructor does not need to perform any actions in this implementation.
}

/**
 * @brief Sets the title of the book.
 * 
 * @param name The new title of the book.
*/
void Book::SetBookName(string &name)
{
    // Updates the book's title to the new value provided.
    book_title = name;
}

/**
 * @brief Sets the author of the book.
 * 
 * @param author The new author of the book.
*/
void Book::SetBookAuthor(string &author)
{
    // Updates the book's author to the new value provided.
    book_author = author;
}

/**
 * @brief Sets the ISBN number of the book.
 * 
 * @param ISBN The new ISBN number of the book.
*/
void Book::SetBookNumber(string &ISBN)
{
    // Updates the book's ISBN number to the new value provided.
    book_ISBN = ISBN;
}

/**
 * @brief Sets the genre of the book.
 * 
 * @param gener The new genre of the book. 
*/
void Book::SetBookGener(string &gener)
{
    // Updates the book's genre to the new value provided.
    book_gener = gener;
}

/**
 * @brief Sets the availability status of the book.
 * 
 * @param choise The new availability status of the book (true if available, false otherwise).
*/
void Book::SetBookAvailability(bool &choise)
{
    // Updates the book's availability status to the new value provided.
    availability = choise;
}

/**
 * @brief Gets the title of the book.
 * 
 * @return The title of the book.
*/
string Book::GetBookName()
{
    // Returns the current title of the book.
    return book_title; 
}

/**
 * @brief Gets the author of the book.
 * 
 * @return The author of the book.
*/
string Book::GetBookAuthor()
{
    // Returns the current author of the book.
    return book_author;
}

/**
 * @brief Gets the genre of the book.
 * 
 * @return The genre of the book.
*/
string Book::GetBookGener()
{
    // Returns the current genre of the book.
    return book_gener;
}

/**
 * @brief Gets the ISBN number of the book.
 * 
 * @return The ISBN number of the book.
*/
string Book::GetBookNumber()
{
    // Returns the current ISBN number of the book.
    return book_ISBN;
}

/**
 * @brief Gets the availability status of the book.
 * 
 * @return The availability status of the book (true if available, false otherwise).
*/
bool Book::GetBookAvailability()
{
    // Returns the current availability status of the book.
    return availability;
}
