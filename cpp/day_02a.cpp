
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool isValidColorValue(const std::string& color, int value) {
	if (color=="green") {return !(value > 13); }
	if (color=="blue")	{return !(value > 14); }
	if(color=="red")    {return !(value > 12); }
	return true;
}
bool getStartIndex(std::string game_string) {
	std::regex e_basic_regex ("\\s([0-9]+)\\s(red|blue|green)");   // matches words beginning by "sub"

	std::regex_iterator<std::string::iterator> rit ( game_string.begin(), game_string.end(), e_basic_regex );
	std::regex_iterator<std::string::iterator> rend;

	while (rit!=rend) {
		std::string a = rit->str();
		std::string color = a.substr(a.find_last_of(' ')+1);
		if (!isValidColorValue(color,stoi(a))) {
			return false;
		}
		++rit;
	}

	return true;
}

int fileIterator(std::ifstream& inputFile) {
	int total = 0; int game=1; std::string line;
	while (getline(inputFile,line)) {
		if (getStartIndex(line)) {
			total += game;
		}
		game++;
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

