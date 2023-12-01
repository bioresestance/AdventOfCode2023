
#include <iostream>
#include "InputFile.hpp"

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

        std::cout << line << " : " << hidden_num << std::endl;

        sum += hidden_num;
    }
    std::cout << "The sum of all hidden numbers is: " << sum << std::endl;
}

void part2()
{
    InputFile input_file("day01_input.txt");

    auto lines = input_file.getLines();

    for (auto &line : lines)
    {
        // std::cout << line << std::endl;
    }
}

int main(void)
{
    part1();
    part2();

    return 0;
}