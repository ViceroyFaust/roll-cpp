#include <iostream>
#include <string>
#include <random>

/* TODO
 * - Take a single line of input and parse it
 *  + Either dice notation or exit
 * - produce random output and do calculations
 * - print result to user's screen
 */

std::string getUserInput() {
    std::string output;
    std::cout << "> ";
    std::getline(std::cin, output);
    return output;
}

int main()
{
    std::cout << "Dice Roller" << std::endl;
    std::cout << getUserInput() << std:: endl;
    return 0;
}
