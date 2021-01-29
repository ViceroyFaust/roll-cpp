#include <stdlib.h>
#include "dice.h"

int roll(die toThrow) {
    int number{0};
    int toss;
    for (int i = 0; i < toThrow.num; i++) {
        toss = 1 + rand() % toThrow.sides;
        switch (toThrow.oper) {
            case '+':
                toss += toThrow.val;
                break;
            case '-':
                toss -= toThrow.val;
                break;
            case '*':
                toss *= toThrow.val;
                break;
            case '/':
                toss /= toThrow.val;
                break;
            default:
                break;

        }
        number += toss;
    }
    return number;
}
