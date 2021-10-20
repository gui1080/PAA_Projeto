
def pega_url():
    
    # tratando busca simples
    
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
        
    while(1):
        
        add_or = str(input("Adicionar um 'OR' nessa busca?[Y/N]"))

        if(add_or == 'Y' or add_or == 'y'):
            
            nova_keyword = str(input("Digite sua keyword.\n"))
            nova_keyword = nova_keyword.replace(' ', '+')
            busca_string = str(input("Deve ser buscada essa string exata?[Y/N]\n"))
            
            if(busca_string == 'Y' or busca_string == 'y'):
                
                # busca de termo exato é entre aspas
                nova_keyword = '"' + nova_keyword + '"'
                
            keyword = keyword + '+' + 'OR' + '+' + nova_keyword
            
        add_and = str(input("Adicionar um 'AND' nessa busca?[Y/N]"))
            
        if(add_and == 'Y' or add_and == 'y'):
            
            nova_keyword = str(input("Digite sua keyword.\n"))
            nova_keyword = nova_keyword.replace(' ', '+')
            busca_string = str(input("Deve ser buscada essa string exata?[Y/N]\n"))
            
            if(busca_string == 'Y' or busca_string == 'y'):
                
                # busca de termo exato é entre aspas
                nova_keyword = '"' + nova_keyword + '"'
                
            keyword = keyword + '+' + 'AND' + '+' + nova_keyword
        
        
        if( (add_or == 'N' or add_or == 'n') and (add_and == 'N' or add_and == 'n')):
            print("Url finalizada!")
            break
        
    # url básica
    url = "https://www.google.com/search?q=" + keyword
    
    print("Sua busca:")
    print(url)
    
    lista_urls = []
    
    # a classe recebe a string na lista
    lista_urls.append(url)
    
    return lista_urls 