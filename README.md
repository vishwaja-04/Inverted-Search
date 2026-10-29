Inverted Search Database in C

📌 Description

The Inverted Search Database is a C-based application that efficiently searches for words across multiple text files using an inverted indexing technique. It uses a hash table to organize words based on their first character and linked lists to store word occurrences and associated filenames.

Instead of searching each file individually, the application creates an index of words, their occurrence counts, and the files in which they appear, enabling faster word retrieval.

✨ Features

- Create Database: Build an inverted index from multiple text files.
- Display Database: Display indexed words, their occurrence counts, and associated filenames.
- Search Database: Search for a specific word in the database.
- Save Database: Store the database in a file for future use.
- Update Database: Rebuild or update the database using a previously saved database file.
- File Validation: Validate input text files and check for invalid or duplicate filenames.

 Technologies Used

- Language: C
- Data Structures: Hash Table, Singly Linked Lists, and Linked List-Based Indexing.
- Concepts: Pointers, Dynamic Memory Allocation, File Handling, String Manipulation, and Modular Programming.
- Command-Line Arguments: "argc" and "argv".
- Compiler: GCC

 Learning Outcomes

- Gained practical experience in C programming.
- Understood hash tables and linked-list-based data structures.
- Learned to organize and retrieve data using an inverted index.
- Improved knowledge of pointers and dynamic memory allocation.
- Practised file handling and command-line argument processing.
