# Library Management System

## Overview

The Library Management System (LMS) is a C++ application designed to manage a library’s book collection,

user registrations, and the borrowing/returning process.

This system uses object-oriented programming [ OOP ]concepts, standard template library [ STL ]

(containers, algorithms, and iterators), and smart pointers to handle books, users, 

and their interactions efficiently.


## Features

![Screenshot from 2024-08-03 22-07-24](https://github.com/user-attachments/assets/e340ca4c-11f2-4513-94c4-253f183e4d78)

- Book Management: Add, remove, and search for books by title, author, or genre.

- User Management: Register new users, remove users, and track borrowed books.

- Borrowing and Returning: Allow users to borrow and return books with appropriate error handling.

- Search Functionality: Search for books by title, author, or genre.

- Memory Management: Efficient management using smart pointers.  

- Error Handling: Handle errors such as book not found, user not found, and books already borrowed.


## Prerequisites

- A C++ compiler (g++).

- CMake (for build configuration).


## Installation

1. Clone the repository:

		git clone <repository-url>

		cd <repository-directory>

2. Build the project:
	
	If using CMake:
	
		mkdir build
		
		cd build
		
		cmake --build ..
		
		cmake ..
	
	or simply use [ g++ ] to compile: 
	
		g++ main.cpp library.cpp user.cpp book.cpp -o my_library 

		
## Usage

1. Run the application:
		
		./my_library
		
2. Interact with the command-line menu:
		
	The application will present a menu with options to add, remove, register, 
		
	display, borrow, return, and search for books and users.



## Example Commands

- Add a Book:
		1
		
		enter the book name: LinearAlgebra
		
		enter the book author: Dr. Yasser
		
		enter the book category: Mathematics
		
		enter the book ISBN: 123qwe
		
- Remove a Book:

		2
		
		enter the serial number of the book to remove: 123qwe
		
- Register a User:

		3

		enter the user name: John Doe

		enter the user id: 1
		
- Borrow a Book:

		7
		
		enter the user id: 1
		
		enter the book serial number: 123qwe
		
- Return a Book:

		8

		enter the user id: 1

		enter the book serial number: 123qwe



## Code Structure

- 'main.cpp': Entry point of the application with command-line interface.

- 'library.cpp' / 'library.hpp' : Implementation and interface for the library system.

- 'user.cpp' / 'user.hpp' : Implementation and interface for managing users.

- 'book.cpp' / 'book.hpp' : Implementation and interface for managing books.	





		

