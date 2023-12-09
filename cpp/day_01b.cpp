#include <iostream>
#include <fstream>
#include <map>

const std::map<std::string,int> stringNumberMap = {
    { "1", 1},
    { "one", 1},
    { "2", 2},
    { "two", 2},
    { "3", 3},
    { "three", 3},
    { "4", 4},
    { "four", 4},
    { "5", 5},
    { "five", 5},
    { "6", 6},
    { "six", 6},
    { "7", 7},
    { "seven", 7},
    { "8", 8},
    { "eight", 8},
    { "9", 9},
    { "nine", 9}
};


int getLastNumber(std::string& line) {
    std::reverse(line.begin(), line.end());
    size_t index = line.length() + 2; int value = 0;
    for (std::pair<const std::string, int> string_number_map : stringNumberMap) {
        std::string testVal=string_number_map.first;std::reverse(testVal.begin(),testVal.end());
        size_t tempIndex = line.find(testVal);
        if (tempIndex != std::string::npos && tempIndex < index) {
            index = tempIndex;
            value = string_number_map.second;
        }
    }
    return value;
}

int getFirstNumber(const std::string& line) {
    size_t index = line.length() + 2; int value = 0;
    for (std::pair<const std::string, int> string_number_map : stringNumberMap) {
        size_t tempIndex = line.find(string_number_map.first);
        if (tempIndex != std::string::npos && tempIndex < index) {
            index=tempIndex;
            value = string_number_map.second;
        }
    }
    return value;
}

int fileIterator(std::ifstream& inputFile) {
    int total = 0;
    std::string line;
    while (getline(inputFile,line)) {
        total += (getFirstNumber(line) * 10)+getLastNumber(line);
    }
    return total;
}

int main() {
    std::ifstream myFile ("../input/day_1_input.txt");
    if (myFile.is_open()) {
        std::cout << fileIterator(myFile) << std::endl;
    }
    myFile.close();
    return 0;
}