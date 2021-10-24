import os
import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.http import Request

from criador_url import pega_url
from salva_pagina import salva_pagina

fb_pages = 0
MAX_FB_PAGES = 500


def createDirs(path):
    try:
        os.makedirs(path)
    except FileExistsError:
        pass


class firstSpider(scrapy.Spider):
    createDirs("./data/downloaded_pages")
    createDirs("./data/words")

    name = "basic"
    start_urls = pega_url()

    custom_settings = {
        'DEFAULT_REQUEST_HEADERS': {
            'Accept-Language': 'pt'
        }
    }

    def parse(self, response):
        global fb_pages, MAX_FB_PAGES

        if response.status != 200:
            return

        res_lang: str = None
        res_type: str = None

        for (header, value) in response.headers.items():
            header_name = header.decode().lower()
            if(header_name == "content-language"):
                res_lang = value[0].decode()

                if "pt" not in res_lang and "en" not in res_lang:
                    return

                if res_type != None:
                    break

            elif (header_name == "content-type"):
                res_type = value[0].decode()

                if "text/html" not in res_type:
                    return

                if res_lang != None:
                    break

        if res_lang == None and ".br" not in response.url:
            return

        xlink = LinkExtractor()
        salva_pagina(response)

        for link in xlink.extract_links(response):
            if "facebook" in link.url:
                if fb_pages > MAX_FB_PAGES:
                    continue
                fb_pages += 1

            if "docs.github.com" in link.url:
                continue

            # print(link.text, "\n", link.url, "\n")
            yield Request(link.url)
