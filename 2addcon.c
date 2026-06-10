#include <stdio.h>      // Standard input output
#include <stdlib.h>     // Standard library
#include <string.h>     // String functions
#include "contact.h"    // Structure and function declarations

int validate_name(char *n);   // Prototype for name validation
int validate_phone(char *m);  // Prototype for phone validation
int validate_email(char *e);  // Prototype for email validation
int validate_prevdata(char *a , AddressBook *addressBook); // Check duplicates

int attempts = 0;  // Global counter for validation attempts

void createContact(AddressBook *addressBook)
{
    // Prevent adding more than 100 contacts
    if(addressBook->contactCount > 99)
    {
        printf("\033[1;31mList is full......\n\033[0m");
        return;
    }

    // UI header
    printf("---------------------------------------------------\n");
    printf("                  ADD CONTACT                      \n");
    printf("---------------------------------------------------\n");

    char name[30], phone[11] ,email[40] , location[30];
    int yes , temp1 , temp2;
    
    attempts = 0;

labeln:
    printf("Enter Name: ");
    scanf(" %[^\n]",name);  // Read full name with spaces

    if(temp1 = validate_name(name))  // Validate name
    {
        printf("\033[1;31mEnter a valid Name(Rakesh R)\n\033[0m");
        if(temp1 == 2)
        {
           printf("You need to enter name\n");
           printf("Enter number \n1.YES \t2.NO\n");
           scanf("%d",&yes);
           if(yes == 2)
            return;
           else 
            attempts = 0;
        }        
        goto labeln;
    }

    attempts = 0;

labelm:
    printf("Enter Mobile number: ");
    scanf(" %[^\n]",phone);

    temp1 = validate_phone(phone);               // Validate phone format
    temp2 = validate_prevdata(phone , addressBook);  // Check duplicate phone

    if(temp1 || temp2)
    {
        if(temp1)
         printf("\033[1;31mEnter a valid Phone number(8050497669)\n\033[0m");
        
        if(temp2)
           printf("\033[1;31mEnter unique Phone number\n\033[0m");

         if(temp1 > 2  || temp2 > 3)
         {
            printf("You need to enter number\n");
            printf("Enter number \n1.YES \t2.NO\n");
            scanf("%d",&yes);
            if(yes == 2)
              return;
            else
              attempts = 0;
         }
                
        goto labelm;
    }

    attempts = 0;

labelg:
    printf("Enter Gmail id: ");
    scanf(" %[^\n]",email);

    temp1 = validate_email(email);                // Validate email
    temp2 = validate_prevdata(email , addressBook); // Check duplicate email

    if(temp1 || temp2)
    {
        if(temp1)
         printf("\033[1;31mEnter a valid Email Id(ra__12@g__.com)\n\033[0m");
        
         if(temp2)
           printf("\033[1;31mEnter unique Email ID\n\033[0m");

         if(temp1 > 2 || temp2 > 3)
         {
             printf("You need to enter email\n");
             printf("Enter number \n1.YES \t2.NO\n");
             scanf("%d",&yes);
             if(yes == 2)
               return;
             else
              attempts = 0;
         }
        goto labelg;
    }
    
    attempts = 0;

labell:
    printf("Enter Location: ");
    scanf(" %[^\n]",location);

    if(temp1 = validate_name(location))  // Validate location
    {
        printf("\033[1;31mEnter a valid Location(Bhadravathi)\n\033[0m");
        if(temp1 == 2)
        {
            printf("You need to enter location\n");
            printf("Enter number \n1.YES \t2.NO\n");
            scanf("%d",&yes);
            if(yes == 2)
              return;
            else 
              attempts = 0;
        }
        goto labell;
    }

    // Copy validated data into structure
    strcpy(addressBook->contacts[addressBook->contactCount].name , name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone , phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email , email);
    strcpy(addressBook->contacts[addressBook->contactCount].location , location);

    addressBook->contactCount++;  // Increase count
    printf("\033[1;32mDetails saved successfully...\n\033[0m");
}

int validate_name(char *n)
{   
    attempts++;  // Increment attempt count
    while(*n)
    {
        // Allow alphabets, space and dot
        if((*n >= 'a' && *n <= 'z') || (*n >= 'A' && *n <= 'Z') || *n == ' ' || *n =='.')
         n++;
        else
         return attempts;
    }
    return 0;
}

int validate_phone(char *m)
{ 
    attempts++;
    int count = 0;

    // Reject numbers starting from 0–5
    if(*m >= '0' && *m <= '5')
      return attempts;

    while(*m)
    {
        if(*m >= '0' && *m <= '9')
         m++;
        else
         return attempts;
        count++;
    }

    if(count != 10)  // Must be 10 digits
     return attempts;

    return 0;
}

int validate_email(char *e)
{
    attempts++;

    char *ptr= strchr(e , '@');  // Check '@'
    if(ptr == NULL || strstr(e , ".com") == NULL)
     return attempts;

    if(*e < 'a' || *e > 'z')  // First letter lowercase
     return attempts;

    ptr++;
    if(*ptr < 'a' || *ptr > 'z') // Letter after '@'
     return attempts;

    int flag = 0;

    while(*e)
    {
        if(*e == '@')
           flag++;

        if(*e >= 'A' && *e <= 'Z')  // No uppercase allowed
          return attempts;

        e++;
    }

    if(flag > 1)  // Only one '@'
      return attempts;

    return 0;
}

int validate_prevdata(char *a , AddressBook *addressBook)
{
    attempts++;
    
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        // Check duplicate phone or email
        if(strstr(addressBook->contacts[i].phone , a) ||
           strcasestr(addressBook->contacts[i].email , a))
        {
            return attempts;
        }
    }

    return 0;
}