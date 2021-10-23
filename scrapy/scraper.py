import os
import scrapy 
from scrapy.linkextractors import LinkExtractor
from scrapy.http import Request

from criador_url import pega_url 
from salva_pagina import salva_pagina

fb_pages = 0
MAX_FB_PAGES = 500


class firstSpider(scrapy.Spider):
    try:
        os.mkdir("./downloaded_pages")
    except FileExistsError:
        pass
    
    name = "basic"
    start_urls = pega_url()
  

    def parse(self, response):
        global fb_pages, MAX_FB_PAGES
        
        xlink = LinkExtractor()
        salva_pagina(response)
        
        for link in xlink.extract_links(response):
            if "facebook" in link.url:
                if fb_pages > MAX_FB_PAGES:
                    continue
                fb_pages += 1
            
            print(link.text, "\n", link.url, "\n")
            yield Request(link.url)