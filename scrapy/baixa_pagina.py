import requests
from bs4 import BeautifulSoup

def pega_pagina(url, contador):
    
    html = requests.get(url)
    
    soup = BeautifulSoup(html.text)
    #print(soup.prettify())

    arq_nome = 'pagina' + str(contador) + '.html'

    f = open(arq_nome, 'w')
    f.write(soup.prettify())
    f.close
    
    return True