from bs4 import BeautifulSoup

def salva_pagina(response, contador):
    
    soup = BeautifulSoup(response.text)

    arq_nome = './downloaded_pages/pagina' + str(contador) + '.html'

    f = open(arq_nome, 'w')
    f.write(soup.prettify())
    f.close
    
    f = open("LISTA_LINKS.txt", 'a')
    f.write(response.url)
    
    f.write("\n")
    
    f.close
    
    return True