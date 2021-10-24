#include "../include/utils.hpp"

std::string lower(std::string s) {
    std::for_each(s.begin(), s.end(), [](char &c) {
        c = std::tolower(c);
    });
    return s;
}
