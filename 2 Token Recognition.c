#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isOperator(char token) {
    char operators[] = "+-*/%=&|><!^";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (token == operators[i]) {
            return 1;
        }
    }
    return 0;
}
int isKeyword(char *token) {
    char *keywords[] = {
        "int", "float", "char", "if", "else", "while", "for"
        // Add more C keywords as needed
    };
    
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
} 
int isIdentifier(char *token) {
    if (isalpha(token[0]) || token[0] == '_') {
        for (int i = 1; token[i] != '\0'; i++) {
            if (!isalnum(token[i]) && token[i] != '_') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int isConstant(char *token) {
    int i = 0;
    if (token[i] == '-' || token[i] == '+') {
        i++;
    }
    for (; token[i] != '\0'; i++) {
        if (!isdigit(token[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char code[1000];
    char *token;
    const char delimiters[] = " \t\n,;(){}[]";

    printf("Enter C code (max 1000 characters):\n");
    fgets(code, sizeof(code), stdin);

    token = strtok(code, delimiters);

    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } else if (isConstant(token)) {
            printf("Constant: %s\n", token);
        } else if (isOperator(token[0])) {
            printf("Operator: %s\n", token);
        }
        token = strtok(NULL, delimiters);
    }

    return 0;
}