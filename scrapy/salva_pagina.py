import re
from bs4 import BeautifulSoup

contador = 0


def salva_pagina(response):
    global contador

    soup = BeautifulSoup(response.text)

    arq_nome = f"pagina{str(contador)}.html"

    f = open("./data/downloaded_pages/" + arq_nome, 'w')
    f.write(soup.prettify())
    f.close()

    words = re.split('\W+', soup.getText())

    f = open("./data/words/" + arq_nome, "w")
    f.write(" ".join(words).lower())
    f.close()

    listFile = open("./data/LISTA_LINKS.txt", 'a')
    listFile.write(response.url)
    listFile.write("\n")

    contador += 1

    return True
