#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
std::string zipMinus(std::string str1, std::string str2) {
    std::string::iterator it1;
    std::string::iterator it2 = str2.begin();
    std::string result = "";
    for (it1 = str1.begin(); it1 != str1.end(); it1++) {
        result += *it1 - *it2;
        it2++;
    }
    return result;
}

void findDiff(std::string str1, std::string str2) {
    std::string::iterator it1;
    std::string::iterator it2 = str2.begin();
    std::cout << "Result: ";
    for (it1 = str1.begin(); it1 != str1.end(); it1++) {
        if (*it1 == *it2) {
            std::cout << *it1;
        }
        it2++;
    }
}

bool notZero(char c) {
    return c != 0;
}

int main()
{
    std::ifstream file1("input");
    std::string line1;
    std::list<std::string> list;
    while (std::getline(file1, line1)) {
        list.insert(list.end(), line1);
    }
    std::ifstream file2("input");
    std::string line2;
    while (std::getline(file2, line2)) {
        std::list<std::string>::iterator it;
        for (it = list.begin(); it != list.end(); it++) {
            line1 = *it;
            std::string diff = zipMinus(line1, line2);
            if (std::count_if(diff.begin(), diff.end(), notZero) == 1) {
                std::cout << "Match: " << line1 << " and " << line2 << "\n";
                findDiff(line1, line2);
                return 0;
            }
        }
    }
    std::cout << "Result: " << "???";
    return 0;
}