#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
int main()
{
    int twoCount = 0;
    int threeCount = 0;
    std::ifstream file ("input");
    std::string line;
    while (std::getline(file, line)) {
        std::string::iterator it;
        bool twoFound = false;
        bool threeFound = false;
        for (it = line.begin(); it != line.end(); it++) {
            char c = *it;
            int count = std::count(line.begin(), line.end(), c);
            twoFound |= count == 2;
            threeFound |= count == 3;
            if (twoFound && threeFound) {
                break;
            }
        }
        if (twoFound) {
            twoCount++;
        }
        if (threeFound) {
            threeCount++;
        }
    }
    std::cout << "Result: " << twoCount * threeCount;
    return 0;
}