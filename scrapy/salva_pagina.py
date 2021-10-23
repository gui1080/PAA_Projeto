from bs4 import BeautifulSoup

contador = 0

def salva_pagina(response):
    global contador
    
    soup = BeautifulSoup(response.text)

    arq_nome = f"./downloaded_pages/pagina{str(contador)}.html"

    f = open(arq_nome, 'w')
    f.write(soup.prettify())
    f.close
    
    f = open("LISTA_LINKS.txt", 'a')
    f.write(response.url)
    f.write("\n")
    f.close

    contador += 1
    
    return True