
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <__ranges/split_view.h>

using namespace std;

int main() {
	std::ifstream inputFile; inputFile.open("../input/day_2_input.txt");
	if (!inputFile.is_open()) { return 0;}
	int sum{};
	int gameId = 1;
	string l;
	while (getline(inputFile,l))
	{
		auto c1 = l.find(':');
		auto sets_line = l.substr(c1 + 2);
		auto sets = std::ranges::views::split(regex("; "), sets_line);
		unordered_map<string, int> cubes;
		cubes["red"] = 0;
		cubes["green"] = 0;
		cubes["blue"] = 0;
		bool possible = true;
		for(auto subset_line : sets)
		{
			auto cubes_line = ranges::views::split(regex(", "), subset_line);
			for(auto cube : cubes_line)
			{
				regex re("(\\d+)\\s(\\w+)");
				smatch m;
				regex_match(cube, m, re);
				auto n = stoi(m[1].str());
				auto c = m[2].str();
				cubes[c] = n;
			}
			if(cubes["red"] > 12 || cubes["green"] > 13 || cubes["blue"] > 14)
			{
				possible = false;
				break;
			}
		}
		if(possible)
		{
			sum += gameId;
		}
		gameId++;
	}
	inputFile.close();
	return sum;
}

