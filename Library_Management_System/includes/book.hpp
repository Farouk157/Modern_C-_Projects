#ifndef _BOOK_HPP_
#define _BOOK_HPP_

// Use the standard namespace for convenience
using namespace std;

/**
 * @brief A class representing a book in a library.
 * 
 * The Book class encapsulates information about a book, including its title, author,
 * genre, ISBN, and availability status. It provides methods to get and set these attributes.
 */
class Book
{
    private: 
        // The title of the book. 
        string book_title;
        // The author of the book.
        string book_author;
        // The genre of the book. 
        string book_gener;
        // The ISBN number of the book.
        string book_ISBN;
        // The availability status of the book
        bool availability;
    
    public:

        /**
         * @brief Default constructor for the Book class.
         * 
         * Initializes a Book object with default values.
        */
        Book();

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
        Book(const string &title,const string &author,const string &gener,const string &ISBN);
        
        /**
         * @brief Destructor for the Book class.
         * 
         * Cleans up any resources used by the Book object.
        */
        ~Book();

        /**
         * @brief Sets the title of the book.
         * 
         * @param name The new title of the book.
        */
        void SetBookName(string &name);

        /**
         * @brief Sets the ISBN number of the book.
         * 
         * @param ISBN The new ISBN number of the book.
        */
        void SetBookNumber(string &ISBN);
        
        /**
         * @brief Sets the author of the book.
         * 
         * @param author The new author of the book.
        */
        void SetBookAuthor(string &author);

        /**
         * @brief Sets the genre of the book.
         * 
         * @param gener The new genre of the book. 
        */
        void SetBookGener(string &gener);  

        /**
         * @brief Sets the availability status of the book.
         * 
         * @param choise The new availability status of the book (true if available, false otherwise).
        */
        void SetBookAvailability(bool &choise); 

        /* getter methods */

        /**
         * @brief Gets the title of the book.
         * 
         * @return The title of the book.
        */
        string GetBookName();

        /**
         * @brief Gets the author of the book.
         * 
         * @return The author of the book.
        */
        string GetBookAuthor();

        /**
         * @brief Gets the genre of the book.
         * 
         * @return The genre of the book. 
        */
        string GetBookGener();

        /**
         * @brief Gets the ISBN number of the book.
         * 
         * @return The ISBN number of the book.
        */
        string GetBookNumber();

        /**
         * @brief Gets the availability status of the book.
         * 
         * @return The availability status of the book (true if available, false otherwise).
        */
        bool GetBookAvailability();
};



#endif