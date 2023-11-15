#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_INPUT 100

// SLR Parsing Table
int parsingTable[5][6] = {
    { 1, -1, -1,  1,  2, -1},
    {-1,  3, -1, -1, -1,  0},
    {-1,  6,  4, -1, -1, -1},
    { 7, -1, -1,  7,  8, -1},
    {-1, 10,  9, -1, -1, -1}
};

typedef struct {
    char symbol;
    int state;
} StackItem;

StackItem stack[MAX_STACK];
char input[MAX_INPUT];

int top = -1;

void push(char symbol, int state) {
    if (top < MAX_STACK - 1) {
        top++;
        stack[top].symbol = symbol;
        stack[top].state = state;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

void parse() {
    int i = 0;
    push('0', 0);

    while (1) {
        // Get the current state from the top of the stack
        int currentState = stack[top].state;

        // Get the next input symbol
        char nextSymbol = input[i];

        // Look up the action in the parsing table
        int action = parsingTable[currentState][nextSymbol - '0'];

        if (action == -1) {
            printf("Error: Invalid input at position %d\n", i);
            break;
        } else if (action == 0) {
            printf("Accepted\n");
            break;
        } else if (action > 0) {
            // Shift
            push(nextSymbol, action);
            i++;
        } else if (action < 0) {
            // Reduce
            int production = -action;
            // Perform reduce operation (pop 2 * production_length symbols)
            pop();  // Pop non-terminal
            pop();  // Pop state

            // Get the new state from the top of the stack
            currentState = stack[top].state;

            // Push the non-terminal symbol
            push('E', parsingTable[currentState][production]);

            // Print the production
            printf("Reduced by production %d\n", production);
        }
    }
}

int main() {
    printf("Enter the input string: ");
    scanf("%s", input);

    parse();

    return 0;
}