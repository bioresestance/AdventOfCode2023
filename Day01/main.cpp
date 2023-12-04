
#include "InputFile.hpp"
#include <iostream>
#include <array>
#include <utility>
#include <cstring>

std::array<std::pair<std::string, uint8_t>, 9> string_nums =
    {
        {
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9},
        }};

void part1()
{
    InputFile input_file("day01_input.txt");

    auto lines = input_file.getLines();

    uint64_t sum = 0;

    for (auto &line : lines)
    {
        uint32_t first_num = 0;
        uint32_t second_num = 0;
        bool first_num_found = false;

        for (char &c : line)
        {
            // If the character is a digit
            if (c >= '0' and c <= '9')
            {
                if (!first_num_found)
                {
                    first_num = c - '0';
                    // The first may be the last if only one number found
                    second_num = first_num;
                    first_num_found = true;
                }
                else
                {
                    second_num = c - '0';
                }
            }
        }

        uint32_t hidden_num = (first_num * 10) + second_num;

        sum += hidden_num;
    }
    std::cout << "Part 1 - Total sum is: " << sum << std::endl;
}

void part2()
{
    InputFile input_file("day01_input.txt");

    auto lines = input_file.getLines();
    uint64_t sum = 0;

    for (auto &line : lines)
    {
        std::vector<uint8_t> numbers;

        uint8_t first_num = 0;
        uint8_t second_number = 0;
        bool first_found = false;

        // Loop through the entire string, char by char
        for (uint32_t i = 0; i < line.length(); i++)
        {
            int8_t found_num = -1;

            // If the char is a digit.
            if (line[i] >= '0' and line[i] <= '9')
            {
                found_num = line[i] - '0';
            }
            else
            {
                // See if the string version of the number is in the line, starting from the current position
                for (auto &num_str : string_nums)
                {
                    if (strncmp(num_str.first.c_str(), &line[i], num_str.first.length()) == 0)
                    {
                        found_num = num_str.second;
                    }
                }
            }

            // We found a number this round.
            if (found_num != -1)
            {
                // Is the first found.
                if (!first_found)
                {
                    first_num = found_num;
                    second_number = found_num;
                    first_found = true;
                }
                // Not the first.
                else
                {
                    second_number = found_num;
                }
            }
        }
        uint32_t hidden_num = (first_num * 10) + second_number;

        sum += hidden_num;
    }

    std::cout << "Part 2 - Total sum is: " << sum << std::endl;
}

int main(void)
{
    part1();
    part2();

    return 0;
}