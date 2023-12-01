#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class InputFile
{
public:
    /**
     * @brief Takes in a filename and reads the file into a vector of lines
     *
     * @param filename Filename to read
     */
    InputFile(std::string filename = "./input.txt");
    ~InputFile() = default;

    /**
     * @brief Returns a vector of lines from the file
     *
     * @return std::vector<std::string> Vector of lines from the file.
     */
    std::vector<std::string> &getLines();

private:
    /// @brief Filename to read
    std::string _filename;
    /// @brief Vector of lines from the file
    std::vector<std::string> _lines;
    /// @brief File stream
    std::ifstream _file;
};
