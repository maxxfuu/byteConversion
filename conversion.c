#include "conversion.h"

/* Main Logic */
char *hexToDec(const char *input) {
    errno = 0;
    char *endptr;

    unsigned long result = strtoul(input, &endptr, 16);

    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid Hexadecimal or out of range\n"); 
        return 0;
    }
    
    /* Calculate digits needed for decimal representation */
    unsigned long temp = result; 
    int numOfDigits = (temp == 0) ? 1 : 0;

    while (temp > 0) {
        temp /= 10; 
        numOfDigits++;
    }

    /* Allocate Memory for Fixed-Sized Array */
    char *decStr = malloc(numOfDigits + 1);
    if (!numOfDigits) {
        printf("Memory Allocation Error\n");
    }
    
    snprintf(decStr, numOfDigits + 1, "%lu", result); 

    return decStr;
}

char *hexToBin(const char *input) {
    size_t length = strlen(input); 
    char *result = malloc(4 * length + 1);
    
    /* malloc automatically changes the pointer to the correct type */
    const char *hexToBinTable[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };
    
    char *ptr = result;

    for (int i = 0; i < length; i++) {
        char c = input[i];
        int index; 

        if (c >= '0' && c <= '9') {
            index = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            index = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            index = c - 'a' + 10; 
        } else {
            printf("Error: Input invalid, unable to convert information");
            free(result);
            return NULL; 
        }
        strcpy(ptr, hexToBinTable[index]);
        ptr += 4; 
    }
    *ptr = '\0'; /* NULL Terminate the string */

    return result; 
}

char *decToHex(const char* input) {
    errno = 0;
    char *endptr;

    unsigned long value = strtoul(input, &endptr, 10);
    char *result = malloc(20);
    snprintf(result, 20, "%lx", value);

    return result;
}

char *decToBin(const char* input) {
    int index = 0;
    char *endptr;
    char buffer[32];
    unsigned long value = strtoul(input, &endptr, 10);
    
    if (value == 0) {
        char *result = (char *)malloc(2);
        if (!result) return NULL;
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    while (value > 0) {
        buffer[index++] = (value % 2) + '0';
        value /= 2;
    }

    buffer[index] = '\0';
    
    int len = index;
    char *result = (char *)malloc(len + 1);
    if (!result) return NULL;

    for (int i = 0; i < len; i++) {
        result[i] = buffer[len - i - 1]; 
    }

   result[len] = '\0';

    return result;
}

char *binToHex(const char *input) {
    char *endptr; 
    unsigned long value = strtoul(input, &endptr, 2); 
    
    if (*endptr != '\0') {
        return NULL;
    }
    
    char *result = malloc(17); 
    if (!result) {
        return NULL;
    }

    snprintf(result, 17, "%lx", value); 
    return result; 
}

char *binToDec(const char *input) {
    char *endptr; 
    unsigned long value = strtoul(input, &endptr, 2);
    
    char *result = malloc(20);

    snprintf(result, 20, "%lu", value); 
    return result;
}

