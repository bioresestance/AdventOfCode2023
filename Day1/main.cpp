
#include <iostream>
#include "InputFile.hpp"

void part1()
{
    InputFile input_file("day01_input.txt");

    auto lines = input_file.getLines();

    for (auto &line : lines)
    {
        // std::cout << line << std::endl;
    }
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