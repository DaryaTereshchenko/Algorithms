#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Find the position of the operator with the lowest 
 * priority between index h and index t
*/
int findOperator(char *expr, int h, int t) {
    int count = 0;
    int lowestPriorityOp = -1;
    int lowestPriority = 0;

    for (int i = t; i >= h; i--) {
        if (lowestPriority == 0 && (expr[i] == '+' || expr[i] == '-')) {
            lowestPriorityOp = i;
            lowestPriority = 1; // Lowest priority for + and -
        }
        else if (lowestPriority == 0 && (expr[i] == '*' || expr[i] == '/')) {
            lowestPriorityOp = i;
            lowestPriority = 2; // Higher priority for * and /
        }
    }

    return lowestPriorityOp;
}

/**
 * Calculate the result of the expression between index h and index t
*/
float calculator(char *expr, int h, int t) {
    // Check if both sides have a pair of ()
    // Remove them because they don't make any sense
    // ATTENTION: You must check if the '(' and ')' are paired

    int opIndex = findOperator(expr, h, t);

    if (opIndex == -1) {
        // No operator or the given expr is a negative number (-xxx)
        // Hint: use atof() to convert numerical string to number
        return atof(expr + h); // Assuming expr is a valid number
    }
    else {
        // Split the expression into left and right parts and recursively calculate
        float left = calculator(expr, h, opIndex - 1);
        float right = calculator(expr, opIndex + 1, t);

        // Perform the operation based on the operator at opIndex
        switch (expr[opIndex]) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                if (right != 0) {
                    return left / right;
                } else {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
            default:
                printf("Error: Invalid operator\n");
                exit(EXIT_FAILURE);
        }
    }
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    
    // Remove trailing newline character
    if (expr[strlen(expr) - 1] == '\n') {
        expr[strlen(expr) - 1] = '\0';
    }

    float result = calculator(expr, 0, strlen(expr) - 1);
    printf("\nAns = %f\n", result);

    return 0;
}