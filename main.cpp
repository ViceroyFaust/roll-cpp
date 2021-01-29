#include <iostream>
#include <string>
#include "dice.h"

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
    // Setting Default values (old values interfere with new ones)
    toReturn.num = 1;
    toReturn.sides = 1;
    toReturn.oper = 0;
    toReturn.val = 0;

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
    bool exit = false;
    std::cout << "Dice Roller\nPlease enter Dice Notation:\n";
    while (!exit) {
        std::string input = getUserInput();
        if (input != "exit") {
            std::cout << roll(parseNotation(input)) << std::endl;
        } else {
            exit = true;
        }
    }
    return 0;
}
