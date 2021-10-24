#include "../include/index.hpp"

int main(){

    std::ifstream file;
    uint32_t page = 0;
    std::string content;

    while(1){
        file.open("../../words/pagina" + std::to_string(page) + ".html");
        if(file){

            while(1){
                file >> content;
                if(file.eof()) break;
            }

            //std::cout << page << " ";
        }
        else{
            std::cout << std::endl << "Terminado de ler arquivos" << std::endl;
            break;
        }
        page++;
        file.close();
    }

    return 0;
}