#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String handling
#include "contact.h"    // Structure and prototypes

void saveContactsToFile(AddressBook *AddressBook)
{
    FILE *fp = fopen("Address_Book.txt" , "w");  // Open file in write mode (overwrite existing data)

    // Write contact count at the top of file if contacts exist
    if(AddressBook->contactCount > 0)
        fprintf(fp ,"# %2d #\n",AddressBook->contactCount );

    // Loop through all contacts and save in comma-separated format
    for(int i = 0 ; i < AddressBook->contactCount ; i++)
    {
        fprintf(fp , "%s,%s,%s,%s\n",
                AddressBook->contacts[i].name,
                AddressBook->contacts[i].phone,
                AddressBook->contacts[i].email,
                AddressBook->contacts[i].location );
    }

    fclose(fp);  // Close file after saving
}