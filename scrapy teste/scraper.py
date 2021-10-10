import scrapy

# scrapy runspider scraper.py

class DuckSpider(scrapy.Spider):
    name = "duck_spider"
    start_urls = ['https://duckduckgo.com/?q=algoritmos&t=hy&va=g&ia=web']

    def parse(self, response):
        
        SET_SELECTOR = '.result results_links_deep highlight_d result--url-above-snippet'
        
        for link in response.css(SET_SELECTOR):

            NAME_SELECTOR = 'h2 ::text'
            yield {
                'name': link.css(NAME_SELECTOR).extract_first(),
            }
            