#include <iostream>
#include <string>

/* TODO
 * - Take a single line of input and parse it
 *  + Either dice notation or exit
 * - produce random output and do calculations
 * - print result to user's screen
 */

 struct die {
    int num;
    int sides;
    char oper;
    int val;
 };

 // returns a line of user input via string
std::string getUserInput() {
    std::string output;
    std::cout << "> ";
    std::getline(std::cin, output);
    return output;
}

// Parses dice notation, ndsOv, eg 2d4+10, and returns a die struct
die parseNotation(std::string toParse) {
    std::string stringNum{""}; // String representation of a number before casting
    die toReturn;
    enum state { // Tracks the parser's progress
        NUMBER, SIDES, OPERAND
    };
    state progress{NUMBER};

    for (size_t i = 0; i < toParse.length(); i++) {
        switch (progress) {
            case NUMBER:
                 if (toParse[i] == 'd') {
                    progress = SIDES;
                    if (stringNum.length() > 0) {
                        toReturn.num = std::stoi(stringNum);
                        stringNum = "";
                    }
                } else {
                    stringNum += toParse[i];
                }
                break;
            case SIDES:
                if (toParse[i] == '+' || toParse[i] == '-' ||
                    toParse[i] == '*' || toParse[i] == '/') {
                    progress = OPERAND;
                    toReturn.sides = std::stoi(stringNum);
                    stringNum = "";
                    toReturn.oper = toParse[i];
                } else if (i == toParse.length()) {
                    toReturn.sides = std::stoi(stringNum);
                } else {
                    stringNum += toParse[i];
                }
                break;
            case OPERAND:
                stringNum += toParse[i];
                break;
        }
    }
    switch (progress) {
        case NUMBER:
            // toReturn.num = std::stoi(stringNum);
            break;
        case SIDES:
            toReturn.sides = std::stoi(stringNum);
            break;
        case OPERAND:
            toReturn.val = std::stoi(stringNum);
            break;
    }

    return toReturn;
}

int main() {
    std::cout << "Dice Roller" << std::endl;
    die playerDie = parseNotation(getUserInput());
    std::cout << "Amt. of Dice: " << playerDie.num << std::endl;
    std::cout << "Num. of Sides: " << playerDie.sides << std::endl;
    std::cout << "Operator (if applicable): " << playerDie.oper << std::endl;
    std::cout << "Modifier Num: " << playerDie.val << std::endl;
    return 0;
}
