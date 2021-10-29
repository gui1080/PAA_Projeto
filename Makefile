.PHONY: all build index install clean crawl rmv

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
	rm -r data/downloaded_pages/ data/words/ data/LISTA_LINKS.txt || true
	mkdir data/downloaded_pages/ data/words/ 
	touch data/downloaded_pages/.gitkeep data/words/.gitkeep
	

