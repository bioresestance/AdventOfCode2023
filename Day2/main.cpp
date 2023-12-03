
#include "InputFile.hpp"
#include <iostream>
#include <array>
#include <utility>
#include <cstring>
#include <sstream>
#include <optional>

uint8_t getGameNumber(const std::string &line)
{
    std::stringstream stream(line);
    std::string found_game;
    const uint8_t offset = sizeof("Game ") - 1;

    // Split the game from the rest of the string.
    std::getline(stream, found_game, ':');

    std::string game_num_str = std::string(&found_game[offset]);

    uint8_t game_num = std::stoi(game_num_str);

    return game_num;
}

std::optional<std::string> getNextHandful(const std::string &line, uint8_t index)
{
    std::stringstream stream(line);
    std::string handful;

    // Split the game from the rest of the string.
    std::getline(stream, handful, ':');

    for (uint8_t i = 0; i < index + 1; i++)
    {
        if (!std::getline(stream, handful, ';'))
        {
            return std::nullopt;
        }
    }
    return handful;
}

void part1and2()
{
    InputFile input_file("day02_input.txt");

    auto lines = input_file.getLines();

    uint32_t sum = 0;
    uint32_t part2Sum = 0;

    for (auto &line : lines)
    {

        // std::cout << line << std::endl;

        uint8_t game_num = getGameNumber(line);

        uint32_t i = 0;
        uint32_t max_red = 0;
        uint32_t max_green = 0;
        uint32_t max_blue = 0;
        while (1)
        {
            auto handful = getNextHandful(line, i);

            // Out of handfuls
            if (!handful)
            {
                break;
            }
            i++;

            std::stringstream stream(handful.value());

            while (!stream.eof())
            {
                std::string num;
                std::string type;
                stream >> num;
                stream >> type;

                if (type.back() == ',')
                {
                    type.pop_back();
                }

                // std::cout << "Num: " << num << " Type: " << type << std::endl;
                uint32_t number = std::stoi(num);

                if (std::strcmp("red", type.c_str()) == 0)
                {
                    if (number >= max_red)
                    {
                        max_red = number;
                    }
                }
                else if (std::strcmp("green", type.c_str()) == 0)
                {
                    if (number >= max_green)
                    {
                        max_green = number;
                    }
                }
                else if (std::strcmp("blue", type.c_str()) == 0)
                {
                    if (number >= max_blue)
                    {
                        max_blue = number;
                    }
                }
            }
        }

        // std::cout << "Max Red: " << std::to_string(max_red)
        //           << " Max Green: " << std::to_string(max_green)
        //           << " Max Blue: " << std::to_string(max_blue)
        //           << std::endl;

        if ((max_red <= 12) and (max_green <= 13) and (max_blue <= 14))
        {
            sum += game_num;
            // std::cout << "Game " << std::to_string(game_num) << " is possible" << std::endl;
        }
        else
        {
            // std::cout << "Game " << std::to_string(game_num) << " is not possible" << std::endl;
        }

        part2Sum += (max_red * max_green * max_blue);
    }

    printf("Part 01 - Sum is: %d\n", sum);
    printf("Part 02 - Sum is: %d\n", part2Sum);
}

int main(void)
{
    part1and2();

    return 0;
}