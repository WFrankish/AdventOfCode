#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
int main()
{
    int currentFrequency = 0;
    std::list<int> reachedFrequencies;
    while (true) {
        std::ifstream file("input");
        std::string line;
        while (std::getline(file, line)) {
            // input format is +n or -n, parse function happily accepts +;
            int change = std::stoi(line);
            currentFrequency += change;

            std::list<int>::iterator it = std::lower_bound(reachedFrequencies.begin(), reachedFrequencies.end(), currentFrequency);

            if (it != reachedFrequencies.end()) {
                int found = *it;
                if (found == currentFrequency) {
                    std::cout << "Found duplicate frequency: " << currentFrequency;
                    return 0;
                }
            }
            reachedFrequencies.insert(it, currentFrequency);
        }

        std::cout << "Reached end of input, list now has size: " << reachedFrequencies.size() << '\n';
    }
}