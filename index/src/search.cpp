#include "../include/search.hpp"

void showLinks(std::vector<uint32_t> pages, std::vector<std::string> links) {
    for (auto i : pages) {
        printf("%d: %s\n", i, links[i].c_str());
    }
}

void search(Tree &wordTree, std::vector<std::string> &links) {
    std::string input;

    std::vector<std::string> wordList;

    while (true) {
        printf("Entre sua string para pesquisa:\n");

        std::getline(std::cin, input);

        trim(input);

        size_t tokenPos = 0, nextTokenPos = 0;

        std::string token;

        while (nextTokenPos != input.npos) {
            nextTokenPos = input.find(" ", tokenPos);

            if (tokenPos == nextTokenPos) {
                tokenPos++;
                continue;
            }

            token = input.substr(tokenPos, nextTokenPos - tokenPos);
            wordList.push_back(token);

            tokenPos = nextTokenPos + 1;
        }

        std::vector<uint32_t> *vec;
        std::vector<pair_key_vec> pageVectors;

        for (auto s : wordList) {
            vec = wordTree.getValue(s);

            if (vec != nullptr) {
                pageVectors.push_back(std::make_pair(s, vec));
            }
        }

        std::vector<uint32_t> finalResult = doAnd(pageVectors);

        wordList.clear();

        if (finalResult.size() == 0) {
            printf("Palavra não encontrada\n");
            continue;
        }

        showLinks(finalResult, links);
    }
}

std::vector<uint32_t> doAnd(std::vector<pair_key_vec> &pageVectors) {
    std::vector<uint32_t> result, last, current;

    if (pageVectors.size() == 0) {
        return result;
    } else if (pageVectors.size() == 1) {
        return *pageVectors.front().second;
    }

    last = *pageVectors.front().second;

    for (auto it = pageVectors.begin()++; it != pageVectors.end(); it++) {
        std::vector<uint32_t> pageVec = (*(*it).second);
        auto insideIterator = pageVec.begin();

        result.clear();

        for (auto jt = last.begin(); jt != last.end(); jt++) {
            auto auxIterator = std::lower_bound(insideIterator, pageVec.end(), *jt);

            if (auxIterator == pageVec.end()) {
                break;
            }

            if (*auxIterator == *jt) {
                result.push_back(*auxIterator);
            }

            insideIterator = auxIterator;
        }

        last = result;
    }

    return result;
}