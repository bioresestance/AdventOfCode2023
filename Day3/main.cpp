
#include "InputFile.hpp"
#include <iostream>
#include <array>
#include <utility>
#include <cstring>
#include <sstream>
#include <optional>

void part1()
{
    InputFile input_file("day03_input.txt");

    auto lines = input_file.getLines();

    uint32_t sum = 0;
    uint32_t part2Sum = 0;

    for (auto &line : lines)
    {
    }

    printf("Part 01 - Sum is: %d\n", sum);
}

int main(void)
{
    part1();

    return 0;
}