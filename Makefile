.PHONY: clean main

main:
	scrapy runspider scrapy/scraper.py
	
clean:
	rm -rf downloaded_pages || 1
	rm LISTA_LINKS.txt || 1
