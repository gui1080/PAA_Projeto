
def pega_url():
    
    # tratando busca simples
    
    qnts_paginas = int(input("Quantas páginas devem ser baixadas?\n"))
    
    keyword = str(input("Digite sua keyword.\n"))
    keyword = keyword.replace(' ', '+')
    
    busca_string = str(input("Deve ser buscada essa string exata?[Y/N]\n"))
    
    if(busca_string == 'Y' or busca_string == 'y'):
        
        # busca de termo exato é entre aspas
        keyword = '"' + keyword + '"'
    
    # tratando remoção de termos
    
    remove_palavras = str(input("Gostaria de remover algumas palavras da busca?[Y/N]\n"))
    
    if(remove_palavras == 'Y' or remove_palavras == 'y'):
        
        # nessas urls, tem que botar um "+-" para excluir o termo
        # keyword de uma busca por mísseis sem resultados para a China seria:
        # /search?q=misseis+-China
        
        keywords_a_serem_ignoradas = str(input("Digite por favor as palavras a serem retiradas da busca!"))
        keywords_a_serem_ignoradas = '+-' + keywords_a_serem_ignoradas.replace(' ', '+-')
        
        keyword = keyword + keywords_a_serem_ignoradas
        
       
    # url básica
    url = "https://www.google.com/search?q=" + keyword
    
    print("Sua busca:")
    print(url)
    
    lista_urls = []
    
    # a classe recebe a string na lista
    lista_urls.append(url)
    
    # pegando as páginas seguintes do google
    for i in range(qnts_paginas):
        pag = 10
        prox_pag = "&start=" + str(pag)
        
        url_prox_pag = url + prox_pag
        print("PROXPAG")
        print(url_prox_pag)
        lista_urls.append(url_prox_pag)
        pag = pag + 10
    
    return lista_urls 