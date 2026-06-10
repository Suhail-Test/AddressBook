#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String functions
#include "contact.h"    // Structure and prototypes

void searchContact(AddressBook *addressBook);  // Prototype for search function

void deleteContact(AddressBook *addressBook)
{
    int add , n;

    searchContact(addressBook);  // Search contact before deletion

    if(addressBook->contactCount == 0)  // If no contacts exist
        return;

    if(addressBook->arrcount == 0)  // If search found nothing
        return;
    
    if(addressBook->arrcount == 1)  // If only one result, auto select
    {
        add = 1;
        goto delete;
    }

    printf("Enter number which you want to delete\n");
    scanf("%d",&add);

   delete: 
    int delete = addressBook->arr[add - 1];  // Get actual index in contacts array
    

    // UI header
    printf("---------------------------------------------------\n");
    printf("                  DELETE CONTACT                      \n");
    printf("---------------------------------------------------\n");

    // Confirmation before deletion
    printf("\033[1;31mAre you sure you want to delete this contact ?\n Enter number\n 1.YES\t2.NO\n\033[0m");
    scanf("%d",&n);

    if(n == 2)  // If user chooses NO
        return;

    // Shift all contacts left to remove the deleted contact
    for(int i = delete ; i < addressBook->contactCount - 1 ; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;  // Decrease contact count after deletion
}