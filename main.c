#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "conversion.c"

#define BUFFER 1000

/* Create functions in header file to change between different data notation */

int main(void) {
    int choice; 
    char input[BUFFER]; 
    char cleanedString[BUFFER];
    char *result; 

    while(1) {
    
        // Display Menu 
        printf("\n--- Conversion Menu ---\n");
        printf("1. Hexadecimal to Binary\n");
        printf("2. Hexadecimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Decimal to Binary\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Binary to Decimal\n");
        printf("7. Exit\n");
        printf("-------------------------\n");
        printf("\nEnter An Input > "); 
        
        /* Check User Choice */
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input. Please Enter A Number.\n"); 
            while (getchar() != '\n')      /* Clears Buffer */
                continue; 
        }

        if (choice == 7) {
            printf("\n\nExiting...\n");
            exit(1); 
        }

        if (choice > 1 && choice < 8) {
            printf("Input Out Of Range, Try Again!\n");
            continue; 
        }
        
        /* Check User Value */
        printf("Enter Value to Convert > "); 
        if (scanf("%s", input) != 1) { /* Array decays to pointer */
            printf("Invalid Input. Please Enter A Valid Input.\n"); 
            while (getchar() != '\n')      /* Clears Buffer */
                continue; 
        }
        
        /* Clean User Value */
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        } 

        char *str = input; 

        if (*str == '0') {
            (str)++; 
            if (*str == 'x' || *str == 'b' || *str == 'X' || *str == 'B') {
                (str)++;
            }
        } 
        
        strcpy(cleanedString, str); 
        printf("Cleaned String: %s\n", cleanedString); /* Clean User Input*/


        /* Main Conversion Logic */
        switch (choice) {
            case 1:
                result = hexToBin(cleanedString);
                printf("Binar > %s\n", result); 
                break;

        }


    }



    if (!fgets(input, sizeof(input), stdin)) {
        exit(1); 
    }
    
        

    return 0; 
}

/*Take a string, check for the first two characters, check if the last char is end of line character*/

