#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String handling
#include "contact.h"    // Structure and prototypes

void searchContact(AddressBook *addressBook);   // Prototype for search
int validate_name(char *n);                    // Prototype for name validation
int validate_phone(char *m);                   // Prototype for phone validation
int validate_email(char *e);                   // Prototype for email validation
int validate_prevdata(char *a , AddressBook *addressBook); // Duplicate check
extern int attempts;                           // Use global attempts counter

void editContact(AddressBook *addressBook)
{
    char name[30] , phone[11] , email[40] , location[30]; // Buffers for new data
    int add;

    searchContact(addressBook);  // First search the contact to edit

    if(addressBook->contactCount == 0)  // If list empty
        return;
    
    if(addressBook->arrcount == 0)  // If no search results
        return;
    
    if(addressBook->arrcount == 1)  // If only one result, auto select
    {
        add = 1;
        goto edit;
    }

    printf("Enter number which you want to edit\n");
    scanf("%d",&add);

edit:
    int edit = addressBook->arr[add - 1];  // Get actual index in contacts array

    // UI header
    printf("---------------------------------------------------\n");
    printf("                  EDIT CONTACT                      \n");
    printf("---------------------------------------------------\n");

    int n , yes , temp;

    do
    {
        // Edit menu
        printf("Enter number\n");
        printf("1. To edit name.\n");
        printf("2. To edit mobile number.\n");
        printf("3. To edit gmail.\n");
        printf("4. To edit location.\n");
        printf("5. To saved\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                attempts = 0;
labeln:
                printf("Enter name: ");
                scanf(" %[^\n]",name);

                if(temp = validate_name(name))  // Validate name
                {
                    printf("\033[1;31mInvalid input..\n\033[0m");
                    if(temp == 3)
                    {
                        printf("You need to enter name\n");
                        printf("Enter number \n1.YES \t2.NO\n");
                        scanf("%d",&yes);
                        if(yes == 2)
                            break;
                        else 
                            attempts = 0;
                    }
                    goto labeln;
                }
                strcpy(addressBook->contacts[edit].name , name); // Update name
                break;

            case 2:
                attempts = 0;
labelm:
                printf("Enter mobile number: ");
                scanf(" %[^\n]",phone);

                temp = validate_phone(phone);  // Validate phone
                
                if(temp || validate_prevdata(phone , addressBook))
                {
                    printf("\033[1;31mInvalid input...\n\033[0m");
                    if(temp == 3)
                    {
                        printf("You need to enter number\n");
                        printf("Enter number \n1.YES \t2.NO\n");
                        scanf("%d",&yes);
                        if(yes == 2)
                            break;
                        else
                            attempts = 0;
                    }
                    goto labelm;
                }
                strcpy(addressBook->contacts[edit].phone , phone); // Update phone
                break;

            case 3:
                attempts = 0;
labelg:
                printf("Enter gmail id: ");
                scanf(" %[^\n]",email);

                temp = validate_email(email);  // Validate email

                if(temp || validate_prevdata(email , addressBook))
                {
                    printf("\033[1;31mInvalid input...\n\033[0m");
                    if(temp == 3)
                    {
                        printf("You need to enter email\n");
                        printf("Enter number \n1.YES \t2.NO\n");
                        scanf("%d",&yes);
                        if(yes == 2)
                            break;
                        else
                            attempts = 0;
                    }
                    goto labelg;
                }
                strcpy(addressBook->contacts[edit].email , email); // Update email
                break;

            case 4:
                attempts = 0;
labell:
                printf("Enter location: ");
                scanf(" %[^\n]",location);

                if(temp = validate_name(location))  // Validate location
                {
                    printf("\033[1;31mInvalid input..\n\033[0m");
                    if(temp == 3)
                    {
                        printf("You need to enter location\n");
                        printf("Enter number \n1.YES \t2.NO\n");
                        scanf("%d",&yes);
                        if(yes == 2)
                            break;
                        else
                            attempts = 0;
                    }
                    goto labell;
                }
                strcpy(addressBook->contacts[edit].location , location); // Update location
                break;

            case 5:
                printf("\033[1;32mDetails saved successfully...\n\033[0m");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(n != 5);  // Repeat until user saves
}