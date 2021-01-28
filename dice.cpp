#include <stdlib.h>

int roll(int amt, int sides, char oper, int val) {
    int number{0};
    for (int i = 0; i < amt; i++) {
        int toss = 1 + rand() % sides;
        switch (oper) {
            case '+':
                toss += val;
                break;
            case '-':
                toss -= val;
                break;
            case '*':
                toss *= val;
                break;
            case '/':
                toss /= val;
                break;
            default:
                toss = 0;

        }
        number += toss;
    }
    return number;
}

int roll(int amt, int sides) {
    return roll(amt, sides, 0, 0);
}

int roll(int sides) {
    return roll(1, sides, 0, 0);
}
