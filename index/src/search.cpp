#include "../include/search.hpp"

void showLinks(std::vector<uint32_t> pages, std::vector<std::string> links) {
    for (int i = 0; i < pages.size(); i++) {
        uint32_t p = pages[i];
        if (p >= links.size()) {
            printf("Link %d não é um indice da lista de links(size:%d)\n", p, links.size());
            exit(1);
        }
        printf("pages[%d] = %d: %s\n", i, p, links[p].c_str());
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
        std::vector<uint32_t> pagesToRemove;

        for (auto s : wordList) {
            if (s[0] == '-') {
                vec = wordTree.getValue(s.substr(1));
            } else {
                vec = wordTree.getValue(s);
            }

            if (vec != nullptr) {
                if (s[0] == '-') {
                    addPages(pagesToRemove, *vec);
                } else {
                    pageVectors.push_back(std::make_pair(s, vec));
                }
            }
        }

        std::vector<uint32_t> andResult = doAnd(pageVectors);
        std::vector<uint32_t> finalResult = removePages(andResult, pagesToRemove);

        wordList.clear();

        if (finalResult.size() == 0) {
            printf("Palavra não encontrada\n");
            continue;
        }

        showLinks(finalResult, links);
    }
}

void addPages(std::vector<uint32_t> &target, std::vector<uint32_t> &vec) {
    auto targetIt = target.begin();
    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto place = std::lower_bound(targetIt, target.end(), *it);

        if (place == target.end()) {
            target.insert(place, it, vec.end());
            return;
        }

        if (*place == *it) {
            continue;
        }

        target.insert(place, *it);

        targetIt = place++;
    }
}

std::vector<uint32_t> removePages(std::vector<uint32_t> &pages, std::vector<uint32_t> &pagesToRemove) {
    std::vector<uint32_t> result;

    auto removeIt = pagesToRemove.begin();

    for (auto it = pages.begin(); it != pages.end(); it++) {
        auto place = std::lower_bound(removeIt, pagesToRemove.end(), *it);

        if (place == pagesToRemove.end()) {
            result.insert(result.end(), it, pages.end());
            return result;
        }

        if (*place == *it) {
            continue;
        }

        result.push_back(*it);

        removeIt = place++;
    }

    return result;
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