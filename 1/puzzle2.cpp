#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
int main()
{
    int currentFrequency = 0;
    std::list<int> reachedFrequencies;
    std::list<int> sortedReachedFrequencies;
    std::ifstream file("input");
    std::string line;
    while (std::getline(file, line)) {
        // input format is +n or -n, parse function happily accepts +;
        int change = std::stoi(line);
        currentFrequency += change;

        reachedFrequencies.insert(reachedFrequencies.end(), currentFrequency);

        std::list<int>::iterator targetPosition = std::lower_bound(sortedReachedFrequencies.begin(), sortedReachedFrequencies.end(), currentFrequency);

        if (targetPosition != sortedReachedFrequencies.end()) {
            int found = *targetPosition;
            if (found == currentFrequency) {
                std::cout << "Found duplicate frequency: " << currentFrequency;
                return 0;
            }
        }

        sortedReachedFrequencies.insert(targetPosition, currentFrequency);
    }

    std::cout << "Reached end of input\n";

    int total = currentFrequency;
    int currentTotal = total;
    while (true) {
        std::list<int>::iterator it;
        for (it = reachedFrequencies.begin(); it != reachedFrequencies.end(); it++) {
            int reachedFrequency = *it;
            currentFrequency = reachedFrequency + currentTotal;
            if (std::binary_search(sortedReachedFrequencies.begin(), sortedReachedFrequencies.end(), currentFrequency)) {
                std::cout << "Found duplicate frequency: " << currentFrequency;
                return 0;
            }
        }
        currentTotal += total;

        std::cout << "Reached end of iteration\n";
    }
}