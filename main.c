#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "conversion.h"

#define BUFFER 1000

int main(void) {
    int choice;
    char *result = NULL;

    char input[BUFFER];
    char cleanedString[BUFFER];

    while(1) {
    
        // Display Menu 
        printf("\n--- Conversion Menu ---\n");
        printf("1. Hexadecimal to Decimal\n");
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

        if (choice < 1 || choice > 7) {
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
        // printf("Cleaned String: %s\n", cleanedString); /* Clean User Input*/

        /* Main Conversion Logic */
        switch (choice) {
            case 1:
                result = hexToDec(cleanedString);
                printf("Decimal > %s\n", result);
                free(result);
                break;

            case 2:
                result = hexToBin(cleanedString);
                printf("Binary > %s\n", result);
                free(result); 
                break;

            case 3:
                result = decToHex(cleanedString);
                printf("HexaDecimal > %s\n", result);
                free(result); 
                break; 

            case 4:
                result = decToBin(cleanedString);
                printf("Binary > %s\n", result);
                free(result); 
                break;

            case 5: 
                result = binToHex(cleanedString); 
                printf("HexaDecimal %s\n", result);
                free(result); 
                break;

            case 6:
                result = binToDec(cleanedString); 
                printf("Decimal %s\n", result);
                free(result);
                break;
 
        }
    }
    return 0; 
}
