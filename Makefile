.PHONY: install clean main index

main: build index
	
build:
	g++ index/src/index.cpp -o index/bin/index.out

index: 
	./index/bin/index.out

install:
	sudo pip install scrapy beautifulsoup4