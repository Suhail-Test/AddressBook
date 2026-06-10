
#include <stdio.h>      // Standard input output functions
#include <stdlib.h>     // Standard library functions
#include <string.h>     // String handling functions
#include "contact.h"    // Header file for structure and prototypes

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fp1 = fopen("Address_Book.txt" , "r+");  // Open file in read/write mode
  
    if (fp1 == NULL) 
    {
        printf("No file found. Starting fresh.\n");  // If file not found, start with empty address book
        return;
    }

    // fseek(fp1 , 0 , SEEK_END);  // Move file pointer to end of file
    // printf("size of file -> %lu\n", ftell(fp1));  // Print total file size

    fseek(fp1 , 7 , SEEK_SET);  // Move file pointer to 7th byte position from start
   // printf("second position -> %lu\n", ftell(fp1));  // Print current file pointer position

    addressBook->contactCount = 0;  // Initialize contact count to 0

    // Read each line from file in comma-separated format and store into structure
    while ((fscanf(fp1, "%[^,],%[^,],%[^,],%[^\n]\n",
           addressBook->contacts[addressBook->contactCount].name,
           addressBook->contacts[addressBook->contactCount].phone,
           addressBook->contacts[addressBook->contactCount].email,
           addressBook->contacts[addressBook->contactCount].location)) == 4)
    {
        addressBook->contactCount++;  // Increment contact count for each successful read
    }

    fclose(fp1);  // Close the file
}



