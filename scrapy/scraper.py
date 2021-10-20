import scrapy 
from scrapy.linkextractors import LinkExtractor

from criador_url import pega_url 

# scrapy runspider scraper.py

class firstSpider(scrapy.Spider): 
    name = "basic"
    start_urls = pega_url(); 
  
    # uma url qualquer do google:
    # "https://www.google.com/search?q=fazendo+teste"
  
    def parse(self, response):
        
        xlink = LinkExtractor()
        
        for link in xlink.extract_links(response):
            print(link.text, link, "\n")