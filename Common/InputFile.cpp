#include "InputFile.hpp"

InputFile::InputFile(std::string filename) : _filename(filename)
{
    // Base path to the input files
    std::string base_path = "../../Inputs/";

    // Open the file
    _file.open(base_path + filename);
    if (!_file.is_open())
    {
        std::cout << "Could not open file: " << filename << std::endl;
        return;
    }

    // Rad in all the lines and store them in the vector
    std::string line;
    while (std::getline(_file, line))
    {
        _lines.push_back(line);
    }

    // Close the file
    _file.close();
}

std::vector<std::string> &InputFile::getLines()
{
    return _lines;
}
