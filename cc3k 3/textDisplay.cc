#include "textDisplay.h"

TextDisplay::TextDisplay(std::vector<std::string> floor)
{
    int width = floor[0].size();
    int rowLength = floor.size();
    for (int i = 0; i < rowLength; i++)
    {
        std::vector<char> chars;
        for (int j = 0; j < width; j++)
        {
            chars.push_back(floor[i][j]);
        }
        map.push_back(chars);
    }
}

std::string TextDisplay::notify(Cell &whoNotified)
{
    size_t r = whoNotified.getInfo().row;
    size_t c = whoNotified.getInfo().col;
    if (whoNotified.getObject() != nullptr)
    {
        map[r][c] = whoNotified.getObject()->getSymbol();
    }
    else
    {
        if (whoNotified.getInfo().type == Type::FloorTile)
        {
            map[r][c] = '.';
        }
        else if (whoNotified.getInfo().type == Type::Passage)
        {
            map[r][c] = '#';
        }
        else if (whoNotified.getInfo().type == Type::Doorway)
        {
            map[r][c] = '+';
        }
    }
    return "";
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td)
{
    for (auto row : td.map)
    {
        for (auto c : row)
        {
            out << c;
        }
        out << std::endl;
    }
    return out;
}
