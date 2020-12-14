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

std::string getUserInput() {
    std::string output;
    std::cout << "> ";
    std::getline(std::cin, output);
    return output;
}

int main() {
    std::cout << "Dice Roller" << std::endl;
    parseNotation(getUserInput());
    return 0;
}
