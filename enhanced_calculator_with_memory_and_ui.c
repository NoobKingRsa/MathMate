#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// Constants
#define MAX_MEMORY 10 // Maximum number of memory slots

// Function prototypes
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float modulus(int a, int b);
float power(float base, float exp);
float squareRoot(float a);

void displayMenu();
void logHistory(const char *operation, float num1, float num2, float result, const char *historyPath);
void clearHistory(const char *historyPath);
void clearScreen();
int isValidInput(float *num);
void manageMemory(float memory[], int *memoryCount);

// Main function
int main(int argc, char *argv[]) {
    int choice;
    float num1, num2, result = 0.0;
    float memory[MAX_MEMORY] = {0}; // Memory slots
    int memoryCount = 0; // Current number of memory values

    // Determine history file location
    char historyPath[256] = "history.log"; // Default location
    if (argc > 1) {
        snprintf(historyPath, sizeof(historyPath), "%s/history.log", argv[1]);
    }

    while (1) {
        clearScreen();
        displayMenu();

        // Input user choice with validation
        printf("Enter your choice (1-12): ");
        if (!isValidInput((float *)&choice) || choice < 1 || choice > 12) {
            printf("Invalid choice! Please enter a valid option (1-12).\n");
            continue;
        }

        // Exit if choice is 12
        if (choice == 12) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Handle special operations
        if (choice == 8 || choice == 9 || choice == 10) {
            manageMemory(memory, &memoryCount);
            continue;
        } else if (choice == 11) {
            clearHistory(historyPath);
            printf("History cleared successfully.\n");
            continue;
        }

        // Input numbers for other operations
        if (choice >= 1 && choice <= 7) {
            printf("Enter the first number: ");
            if (!isValidInput(&num1)) {
                printf("Invalid input! Please enter a number.\n");
                continue;
            }
            if (choice != 6) { // No second number needed for square root
                printf("Enter the second number: ");
                if (!isValidInput(&num2)) {
                    printf("Invalid input! Please enter a number.\n");
                    continue;
                }
            }
        }

        // Perform operation based on user choice
        printf("-----------------------------------\n");
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                logHistory("Addition", num1, num2, result, historyPath);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                logHistory("Subtraction", num1, num2, result, historyPath);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                logHistory("Multiplication", num1, num2, result, historyPath);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                    logHistory("Division", num1, num2, result, historyPath);
                }
                break;
            case 5:
                if ((int)num2 == 0) {
                    printf("Error: Modulus by zero is undefined.\n");
                } else {
                    result = modulus((int)num1, (int)num2);
                    printf("Result: %d %% %d = %.2f\n", (int)num1, (int)num2, result);
                    logHistory("Modulus", num1, num2, result, historyPath);
                }
                break;
            case 6:
                if (num1 < 0) {
                    printf("Error: Cannot calculate square root of a negative number.\n");
                } else {
                    result = squareRoot(num1);
                    printf("Result: sqrt(%.2f) = %.2f\n", num1, result);
                    logHistory("Square Root", num1, 0, result, historyPath);
                }
                break;
            case 7:
                result = power(num1, num2);
                printf("Result: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                logHistory("Power", num1, num2, result, historyPath);
                break;
            default:
                printf("Invalid operation.\n");
                break;
        }
        printf("-----------------------------------\n");
        printf("\nPress Enter to continue...");
        getchar(); getchar(); // Pause for user to see result
    }

    return 0;
}

// Function definitions
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }
float modulus(int a, int b) { return a % b; }
float power(float base, float exp) { return pow(base, exp); }
float squareRoot(float a) { return sqrt(a); }

void displayMenu() {
    printf("Enhanced Calculator\n");
    printf("-------------------\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Square Root (√)\n");
    printf("7. Power (^)\n");
    printf("8. Recall Memory\n");
    printf("9. Add to Memory\n");
    printf("10. Clear Memory\n");
    printf("11. Clear History\n");
    printf("12. Exit\n");
}

void logHistory(const char *operation, float num1, float num2, float result, const char *historyPath) {
    FILE *file = fopen(historyPath, "a");
    if (file == NULL) {
        printf("Error: Unable to save history.\n");
        return;
    }

    // Get current time
    time_t now = time(NULL);
    char *timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0'; // Remove newline character

    fprintf(file, "%s | %s: %.2f, %.2f = %.2f\n", timeStr, operation, num1, num2, result);
    fclose(file);
}

void clearHistory(const char *historyPath) {
    FILE *file = fopen(historyPath, "w");
    if (file != NULL) {
        fclose(file);
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int isValidInput(float *num) {
    char buffer[50];
    char *endptr;

    // Read the input into a buffer
    if (scanf("%49s", buffer) != 1) {
        return 0; // Input failed
    }

    // Attempt to convert the input to a float
    *num = strtof(buffer, &endptr);

    // Check if the entire string was converted (i.e., no extra characters remain)
    if (*endptr != '\0') {
        printf("Invalid input! Please enter a numeric value.\n");
        return 0;
    }

    return 1; // Input is valid
}

void manageMemory(float memory[], int *memoryCount) {
    printf("Memory Management is under construction for advanced features!\n");
}