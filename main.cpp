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

    for (int i = 0; i < toParse.length(); i++) {
        switch (progress) {
            case NUMBER:
                if (toParse.at(i) == 'd') {
                    toReturn.num = std::stoi(stringNum);
                    progress = SIDES;
                    stringNum = "";
                } else {
                    stringNum += toParse.at(i);
                }
                break;
            case SIDES:
                if (toParse.at(i) == '+') {
                    toReturn.sides = std::stoi(stringNum);
                    toReturn.oper = toParse.at(i);
                    stringNum = "";
                } else {
                    stringNum += toParse.at(i);
                }
                break;
            case OPERAND:
                stringNum += toParse.at(i);
                break;
        }
    }
    toReturn.val = std::stoi(stringNum);

    return toReturn;
}

int main() {
    std::cout << "Dice Roller" << std::endl;
    die playerDie = parseNotation(getUserInput());
    std::cout << playerDie.num << std::endl << playerDie.sides << std::endl << playerDie.oper << std::endl << playerDie.val << std::endl;
    return 0;
}
