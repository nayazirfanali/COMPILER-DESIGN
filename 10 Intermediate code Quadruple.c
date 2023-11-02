#include <stdio.h>
#include <stdlib.h>

struct Quadruple {
    char op;
    char arg1;
    char arg2;
    char result;
};
void printQuadruple(struct Quadruple q) {
    printf("<%c, %c, %c, %c>\n", q.op, q.arg1, q.arg2, q.result);
}

int main() {
    struct Quadruple quadruples[100]; 
    int quadCount = 0; 
    quadruples[quadCount].op = '*';
    quadruples[quadCount].arg1 = 'c';
    quadruples[quadCount].arg2 = 'd';
    quadruples[quadCount].result = 't';
    quadCount++;
    quadruples[quadCount].op = '+';
    quadruples[quadCount].arg1 = 'b';
    quadruples[quadCount].arg2 = 't';
    quadruples[quadCount].result = 't';
    quadCount++;
    quadruples[quadCount].op = '=';
    quadruples[quadCount].arg1 = 't';
    quadruples[quadCount].arg2 = '\0';
    quadruples[quadCount].result = 'a';
    quadCount++;

    for (int i = 0; i < quadCount; i++) {
        printf("Quadruple %d: ", i + 1);
        printQuadruple(quadruples[i]);
    }

    return 0;
}