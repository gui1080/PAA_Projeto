#include "../include/utils.hpp"

std::string lower(std::string s) {
    std::for_each(s.begin(), s.end(), [](char &c) {
        c = std::tolower(c);
    });
    return s;
}

void trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));

    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(),
            s.end());
}