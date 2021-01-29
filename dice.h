#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED

struct die {
    int num;
    int sides;
    char oper;
    int val;
 };
int roll(die toThrow);

#endif // DICE_H_INCLUDED
