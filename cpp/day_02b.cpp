//
// Created by Joseph Flynn on 12/3/23.
//
#include <iostream>
#include <fstream>
#include <regex>

int getGamePowerSet(std::string game_string) {
    int maxRed=0,maxGreen=0,maxBlue=0;

    std::regex e_basic_regex ("\\s([0-9]+)\\s(red|blue|green)");

    std::regex_iterator rit ( game_string.begin(), game_string.end(), e_basic_regex );
    std::regex_iterator<std::string::iterator> rend;

    while (rit!=rend) {

        std::string color_number = rit->str();
        std::string color = color_number.substr(color_number.find_last_of(' ')+1);
        int value = stoi(color_number);

        if (color == "red" && value > maxRed) { maxRed=value; }
        if (color == "green" && value > maxGreen) { maxGreen=value; }
        if (color == "blue" && value > maxBlue) { maxBlue=value; }

        ++rit;
    }

    return maxRed*maxGreen*maxBlue;
}

int fileIterator(std::ifstream& inputFile) {
    int total = 0; std::string line;
    while (getline(inputFile,line)) {
        total += getGamePowerSet(line);
    }
    return total;
}

int main() {
    std::ifstream inputFile; inputFile.open("../input/day_2_input.txt");
    if (inputFile.is_open()) {
        std::cout << fileIterator(inputFile) << std::endl;
    }
    inputFile.close();
    return 0;
}