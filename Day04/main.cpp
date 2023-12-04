
#include "InputFile.hpp"
#include <iostream>
#include <array>
#include <utility>
#include <cstring>
#include <sstream>
#include <optional>
#include <unordered_set>

// Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53

void part1()
{
    InputFile input_file("day04_input.txt");

    auto lines = input_file.getLines();

    uint32_t sum = 0;

    for (const auto &line : lines)
    {
        std::unordered_set<uint32_t> winningNumbers;
        std::stringstream stream(line);
        std::string temp_str;
        uint64_t line_count = 0;

        // Skip the first part of the string to get to the numbers.
        std::getline(stream, temp_str, ':');

        // Read in all of the wining numbers, up to the '|' char.
        while (1)
        {
            stream >> temp_str;

            if (temp_str == "|")
            {
                break;
            }

            uint32_t number = std::stoi(temp_str);
            winningNumbers.emplace(number);
        }

        // Now loop through our numbers to see if any were in there.
        while (!stream.eof())
        {
            stream >> temp_str;

            uint32_t number = std::stoi(temp_str);

            // Sets can only have one of the same element.
            if (winningNumbers.count(number) == 1)
            {
                if (line_count == 0)
                {
                    line_count = 1;
                }
                else
                {
                    line_count <<= 1;
                }
            }
        }

        sum += line_count;
    }

    printf("Part 01 - Sum is: %d\n", sum);
}

int main(void)
{
    part1();

    return 0;
}