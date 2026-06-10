

//====================================  P R O J E C T - 1  ==============================================
/*
Student Details :

Name: Rakesh R
addmission no: int26001_004
Subject: C Programming 
Start date: 28 / 03 / 2026
End date: 01 / 04 / 2026

*/

/*
Description:

=> The Address Book Management System is a console-based application developed in C that enables efficient 
  storage and management of contact details. The system allows users to add, view, search, edit, and delete 
  contacts, ensuring easy organization of personal or professional information.

=> It uses structures and file handling to store contact details such as name, mobile number, and email, with 
   proper validation to maintain data accuracy. Contacts are maintained in sorted order, improving readability and 
   search efficiency. The application supports multiple search options, including name, mobile number, and email, 
   making it user-friendly and flexible.

=> This project demonstrates the practical implementation of data structures, string manipulation, modular 
   programming, and file operations in C, providing a real-world solution for contact management.
*/



#include <stdio.h>          // Standard input output functions
#include "contact.h"        // Header file containing structure and function declarations

void loadContactsFromFile(AddressBook *addressBook);  // Function prototype to load contacts from file

int main() 
{
    int choice;                     // Variable to store user menu choice
    AddressBook addressBook;       // Declare address book structure
    addressBook.contactCount = 0;  // Initialize contact count to 0

    loadContactsFromFile(&addressBook);  // Load existing contacts from file at program start

    do 
    {
        // Display menu options
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save and Exit\n");		

        printf("Enter your choice: ");
        scanf("%d", &choice);       // Read user choice
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);   // Call function to create a new contact
                break;

            case 2:
                searchContact(&addressBook);   // Call function to search a contact
                break;

            case 3:
                editContact(&addressBook);     // Call function to edit an existing contact
                break;

            case 4:
                deleteContact(&addressBook);   // Call function to delete a contact
                break;

            case 5:          
                listContacts(&addressBook);    // Call function to list all contacts
                break;

            case 6:
                saveContactsToFile(&addressBook);  // Save all contacts to file before exiting
                printf("\033[1;32mSaving and Exiting...\n\033[0m");  // Print colored exit message
                break;

            default:
                printf("Invalid choice. Please try again.\n");  // Handle invalid input
        }

    } while (choice != 6);  // Repeat menu until user selects Exit

    return 0;   // End of program
}
