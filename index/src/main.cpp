#include "../include/index.hpp"
#include "../include/search.hpp"
#include "../include/utils.hpp"

int main() {
    Tree wordTree;

    index(wordTree);

    search(wordTree);

    return 0;
}