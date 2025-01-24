#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function with memory leak
void memoryLeak() {
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 10;
        // Memory not freed, causing a leak
    }
}

// Function with file handle leak
void fileHandleLeak() {
    FILE* file = fopen("test.txt", "w");
    if (file != NULL) {
        fprintf(file, "Hello, World!");
        // File not closed, causing a handle leak
    }
}

// Function with dynamic memory leak in a loop
void loopLeak() {
    for (int i = 0; i < 5; i++) {
        char* str = (char*)malloc(BUFFER_SIZE * sizeof(char));
        if (str != NULL) {
            snprintf(str, BUFFER_SIZE, "String %d", i);
            printf("%s\n", str);
            // Memory not freed in each iteration, causing multiple leaks
        }
    }
}

// Function with conditional leak
void conditionalLeak(int flag) {
    int* data = (int*)malloc(sizeof(int));
    if (data != NULL) {
        *data = 100;
        
        if (flag) {
            // Memory freed only in this condition
            free(data);
        }
        // If flag is false, memory is not freed, causing a leak
    }
}

// Function with memory leak in error handling
void errorHandlingLeak() {
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return; // Return without freeing in error case
    }
    
    // Use buffer...
    strncpy(buffer, "Some data", BUFFER_SIZE - 1);
    buffer[BUFFER_SIZE - 1] = '\0';
    
    if (strlen(buffer) == 0) {
        printf("Error occurred\n");
        return; // Return without freeing in another error case
    }
    
    free(buffer);
}

int main() {
    memoryLeak();
    fileHandleLeak();
    loopLeak();
    conditionalLeak(0);
    errorHandlingLeak();
    
    return 0;
}
