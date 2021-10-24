#include "../include/index.hpp"
#include "../include/search.hpp"
#include "../include/utils.hpp"

int main() {
    Tree wordTree;
    std::vector<std::string> links;

    index(wordTree);

    readLinks(links);

    search(wordTree, links);

    return 0;
}