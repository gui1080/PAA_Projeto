.PHONY: all build index install clean crawl

all: build run

index/bin: 
	mkdir index/bin || true
	
build:
	make -C index

run: 
	./index/bin/index.out

install:
	sudo pip install scrapy beautifulsoup4

crawl:
	scrapy runspider scrapy/scraper.py
	
clean:
	rm data/downloaded_pages/*.html data/words/*.html data/LISTA_LINKS.txt