#include "../include/search.hpp"

void search(Tree &wordTree) {
    std::string input;

    while (true) {
        std::cin >> input;
        std::vector<uint32_t> *vec = wordTree.getValue(input);

        if (vec == nullptr) {
            printf("Palavra não encontrada\n");
            continue;
        }

        printf("(");
        for (auto i : *vec) {
            printf("%d ", i);
        }
        printf(")\n");
    }
}
