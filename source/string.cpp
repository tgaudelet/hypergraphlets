#include "string.h"

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> temp;

    if (s.size() > 0)
    {
        std::string::size_type prev(0), curr(0);

        while ((curr = s.find(delim, curr)) != std::string::npos)
        {
            temp.push_back(s.substr(prev, curr-prev));
            curr++;
            prev = curr;
        }

        temp.push_back(s.substr(prev));
    }
    return temp;
}

int to_i(const std::string &s)  { return atoi(s.c_str()); }
