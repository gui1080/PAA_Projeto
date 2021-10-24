#include "../include/index.hpp"

void index(Tree &wordTree) {
    std::ifstream file;
    uint32_t page = 0;
    std::string content;

    while (1) {
        file.open("data/words/pagina" + std::to_string(page) + ".html");
        if (file) {
            printf("begin %d", page);

            while (1) {
                file >> content;

                if (file.eof()) {
                    break;
                }

                wordTree.insert(content, page);
            }

            printf(" end\n");
        } else {
            std::cout << "Erro ao ler página" << page << std::endl
                      << "Terminado de ler arquivos" << std::endl;
            break;
        }
        page++;
        file.close();
    }
}