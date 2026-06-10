#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String handling
#include "contact.h"    // Structure and prototypes

void listContacts(AddressBook *addressBook)
{
    int i , j; 

    // Check if address book is empty
    if(addressBook->contactCount == 0)
    {
        printf("\033[1;31mList is empty......\n\033[0m");
        return;
    }

    // Sort contacts alphabetically based on first letter of name (Bubble Sort)
    for(i = 0 ; i < addressBook->contactCount - 1 ; i++)
    {
        for(j = 0 ; j < addressBook->contactCount - 1 - i ; j++)
        {
            if(addressBook->contacts[j].name[0] > addressBook->contacts[j + 1].name[0])
            {
                Contact temp = addressBook->contacts[j];  // Temporary variable for swapping
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }

    // Print table header
    printf("\033[1;33m");
    printf("                          ADDRESS BOOK OF STUDENTS  \n\n");
    printf("# %d #\n",addressBook->contactCount );
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    printf("         Name                    |     Mobile No   |                  Gmail ID                |       Location                 |\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n");

    // Display all contacts
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {
        printf("%2d.%-30s| +91 %-11s | %-40s | %-30s |\n",
               i+1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email,
               addressBook->contacts[i].location );
    }

    printf("\033[0m");  // Reset color
}