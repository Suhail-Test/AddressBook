#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String handling functions
#include "contact.h"    // Structure and function declarations

void searchContact(AddressBook *addressBook)
{
    // Check if address book is empty
    if(addressBook->contactCount == 0)
    {
        printf("\033[1;31mList is empty.......\n\033[0m");
        return;
    }

    // UI header
    printf("---------------------------------------------------\n");
    printf("                  SEARCH CONTACT                      \n");
    printf("---------------------------------------------------\n");

    addressBook->arrcount = 0;  // Reset match counter
    char s[10];                 // Buffer to store search string

    printf("Enter the details to search(name/mobile number/email/location):\n");
    scanf(" %[^\n]",s);         // Read search input

    // Search through all contacts
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        // Check if search string matches any field
        if(strcasestr(addressBook->contacts[i].name , s) ||
           strstr(addressBook->contacts[i].phone , s) ||
           strcasestr(addressBook->contacts[i].email , s) ||
           strcasestr(addressBook->contacts[i].location , s))
        {
            addressBook->arr[addressBook->arrcount] = i;  // Store matching index
            addressBook->arrcount++;                      // Increase match count
        }
    }

    // If no matches found
    if(addressBook->arrcount == 0)
    {
        printf("\033[1;31mContact not found........\n\033[0m");
        return;
    }

    // Print table header
    printf("\033[1;33m");
    printf("                          ADDRESS BOOK OF STUDENTS  \n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("         Name                    |     Mobile No   |                  Gmail ID                |       Location                 |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");

    // Display matched contacts
    for(int i = 0 ; i < addressBook->arrcount; i++)
    {
        printf("%2d.%-30s| +91 %-11s | %-40s | %-30s |\n",
               i+1,
               addressBook->contacts[addressBook->arr[i]].name,
               addressBook->contacts[addressBook->arr[i]].phone,
               addressBook->contacts[addressBook->arr[i]].email,
               addressBook->contacts[addressBook->arr[i]].location);    
    }

    printf("\033[0m");  // Reset color
}