#include <fstream>
#include <iostream>

char getFirstDigitCharacter(const std::string& line) {
    for (int i = 0; i < static_cast<int>(line.length()); i++) {
        if (isdigit(line[i])) {
            return  line[i];
        }
    }
    return '\0';
}

char getLastDigitCharacter(const std::string& line) {
    for (int i = static_cast<int>(line.length()) - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            return  line[i];
        }
    }
    return '\0';
}

int getTotalPerLine(const std::string& line) {
    char total[2];
    total[0] = getFirstDigitCharacter(line);
    total[1] = getLastDigitCharacter(line);
    return std::stoi(total);
}

int getTotalFromFile(std::ifstream& inputFile) {
    int total = 0;
    std::string line;
    while (getline(inputFile,line)) {
        total += getTotalPerLine(line);
    }
    return total;
}

int main() {
    std::ifstream myFile ("../input/day_1_input.txt");
    if (myFile.is_open()) {
        std::cout << getTotalFromFile(myFile);
    }
    myFile.close();
    return 0;
}