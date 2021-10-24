#ifndef INDEX_INCLUDE_H
#define INDEX_INCLUDE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../include/tree.hpp"

void index(Tree &wordTree);

void readLinks(std::vector<std::string> &links);

#endif  // INDEX_INCLUDE_H