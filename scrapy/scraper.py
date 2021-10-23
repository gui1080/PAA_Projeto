import os
import scrapy 
from scrapy.linkextractors import LinkExtractor

from criador_url import pega_url 
from salva_pagina import salva_pagina

# scrapy runspider scraper.py

class firstSpider(scrapy.Spider):

    try:
        os.mkdir("./downloaded_pages")
    except FileExistsError:
        pass
    
    name = "basic"
    start_urls = pega_url()
  
    # uma url qualquer do google:
    # "https://www.google.com/search?q=fazendo+teste"
  
    def parse(self, response):
        
        xlink = LinkExtractor()
        links_salvos = []
        contador = 0
        linksprasalvar = []
        
        print("LINKS EXTRAÍDOS!")
        print("-----------------------")
        for link in xlink.extract_links(response):
            
            print(link, "\n", link.text, "\n", link.url, "\n")
            links_salvos.append(link.url)
            print("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA")
            
            linkatual = link.url
            
            print("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB")
            Pagina = salva_pagina(response, contador)
            contador = contador + 1
            print("CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC")
            linksprasalvar.append(linkatual)
            print("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD")
            
                
        print("-----------------------")
        print(links_salvos)
        