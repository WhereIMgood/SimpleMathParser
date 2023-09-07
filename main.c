#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void split(const char *input, char delimiter, char *list[], int *listSize) {
    char inputCopy[strlen(input) + 1];
    strcpy(inputCopy, input);

    char *token;

    token = strtok(inputCopy, &delimiter);
    while (token != NULL) {
        list[(*listSize)++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
}

int main() {
    char input[50];
    char delimiter = ' ';
    char *list[500];
    int listSize = 0;

    printf("Enter operation: ");
    fgets(input, sizeof(input), stdin); // Read the entire input line

    split(input, delimiter, list, &listSize);

    int firstNumber, secondNumber;
    char operand[2];

    for (int i = 0; i < listSize; i++) {
        if (strcmp(list[i], "+") == 0) {
            strcpy(operand, "+");
        } else if (strcmp(list[i], "-") == 0) {
            strcpy(operand, "-");
        } else if (strcmp(list[i], "/") == 0) {
            strcpy(operand, "/");
        } else if (strcmp(list[i], "*") == 0) {
            strcpy(operand, "*");
        } else if (i % 2 == 0) {
            // Assume it's a number, and update firstNumber or secondNumber
            if (i == 0) {
                firstNumber = atoi(list[i]);
            } else if (i == 2) {
                secondNumber = atoi(list[i]);
            }
        }
    }

    switch (operand[0]) {
        case '+':
            printf("Result: %d\n", firstNumber + secondNumber);
            break;
        case '-':
            printf("Result: %d\n", firstNumber - secondNumber);
            break;
        case '/':
            if (secondNumber != 0) {
                printf("Result: %d\n", firstNumber / secondNumber);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        case '*':
            printf("Result: %d\n", firstNumber * secondNumber);
            break;
        default:
            printf("Invalid operator.\n");
    }

    for (int i = 0; i < listSize; i++) {
        free(list[i]);
    }

    return 0;
}
