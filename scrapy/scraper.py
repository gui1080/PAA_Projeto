import scrapy 
from scrapy.linkextractors import LinkExtractor

import urllib.request, urllib.error, urllib.parse

from criador_url import pega_url 
from baixa_pagina import pega_pagina

# scrapy runspider scraper.py

class firstSpider(scrapy.Spider): 
    name = "basic"
    start_urls = pega_url(); 
  
    # uma url qualquer do google:
    # "https://www.google.com/search?q=fazendo+teste"
  
    def parse(self, response):
        
        xlink = LinkExtractor()
        links_salvos = []
        contador = 0
        
        print("LINKS EXTRAÍDOS!")
        print("-----------------------")
        for link in xlink.extract_links(response):
            
            print(link, "\n", link.text, "\n", link.url, "\n")
            links_salvos.append(link.url)
            
            linkatual = link.url
            
            Pagina = pega_pagina(linkatual, contador)
            contador = contador + 1
                
        print("-----------------------")
        print(links_salvos)
        