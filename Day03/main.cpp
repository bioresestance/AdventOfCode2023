
#include "InputFile.hpp"
#include <iostream>
#include <array>
#include <utility>
#include <cstring>
#include <sstream>
#include <optional>

bool isSymbol(char input)
{
    if (input == '.')
    {
        return false;
    }

    if (std::isdigit(input))
    {
        return false;
    }

    return true;
}

/// @brief Checks if there is a symbol in either the given index or its adjacent spot.
bool isAdjacentSymbol(const std::string &line, uint32_t index)
{
    if (index > line.size() - 1)
    {
        return false;
    }

    if (isSymbol(line[index]))
    {
        return true;
    }

    if (index > 0 and isSymbol(line[index - 1]))
    {
        return true;
    }

    if ((index < (line.size() - 1)) and isSymbol(line[index + 1]))
    {
        return true;
    }

    return false;
}

void part1()
{
    InputFile input_file("day03_input.txt");

    auto lines = input_file.getLines();

    uint32_t sum = 0;
    std::vector<std::string> found_numbers;

    for (uint32_t i = 0; i < lines.size(); i++)
    {
        // Get the line above the current one, if there is one to get.
        std::string above_line = "";
        if (i > 0)
        {
            above_line = lines[i - 1];
        }

        // Gets the current line.
        std::string current_line = lines[i];

        // Get the following line, if there is one to get.
        std::string next_line = "";
        if (i + 1 < lines.size() - 1)
        {
            next_line = lines[i + 1];
        }

        bool num_found = false;
        bool symbol_found = false;
        std::stringstream number;

        // walk the current line to find numbers.
        for (uint32_t j = 0; j < current_line.size(); j++)
        {
            // If the current character is a digit, check all adjacent characters
            if (std::isdigit(current_line[j]))
            {
                // Beginning of the number.
                if (num_found == false)
                {
                    // clear the states.
                    num_found = true;
                    number.str("");
                    number.clear();
                }
                // Add the number to the stream.
                number << current_line[j];

                // Check all three line for an adjacent symbol to the current index.
                if (isAdjacentSymbol(above_line, j) or isAdjacentSymbol(next_line, j) or isAdjacentSymbol(current_line, j))
                {
                    symbol_found = true;
                }

                // std::cout << current_line[j] << " ";
            }

            else if (symbol_found and (!std::isdigit(current_line[j]) or current_line[j + 1] == '\0'))
            {
                std::string new_number;
                number >> new_number;
                found_numbers.emplace_back(new_number);
                symbol_found = false;
                num_found = false;
                std::cout << "Found next to : " << new_number << std::endl;
            }
            else
            {
                symbol_found = false;
                num_found = false;
                number.str("");
                number.clear();
            }
        }
    }

    for (const auto &number : found_numbers)
    {
        uint32_t int_num = std::stoi(number);
        sum += int_num;
    }

    printf("Part 01 - Sum is: %d\n", sum);
}

int main(void)
{
    part1();

    return 0;
}