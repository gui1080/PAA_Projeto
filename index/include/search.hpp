#ifndef SEARCH_INCLUDE_H
#define SEARCH_INCLUDE_H

#include <iostream>

#include "../include/tree.hpp"
#include "../include/utils.hpp"

typedef std::pair<std::string, std::vector<uint32_t> *> pair_key_vec;

void search(Tree &wordTree, std::vector<std::string> &links);

std::vector<uint32_t> doAnd(std::vector<pair_key_vec> &);

#endif  // SEARCH_INCLUDE_H