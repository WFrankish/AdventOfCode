#include <iostream>
#include <fstream>
#include <string>
int main()
{
    int frequency = 0;
    std::ifstream file ("input");
    std::string line;
    while (std::getline(file, line)) {
        // input format is +n or -n, parse function happily accepts +;
        int change = std::stoi(line);
        frequency += change;
        std::cout << line << " => " << frequency << '\n';
    }
    std::cout << "Result: " << frequency;
    return 0;
}