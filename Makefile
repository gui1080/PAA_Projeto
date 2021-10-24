.PHONY: main build index before install 

main: before build index

before: 
	mkdir index/bin || true
	
build: before
	g++ index/src/index.cpp -o index/bin/index.out

index: 
	./index/bin/index.out

install:
	sudo pip install scrapy beautifulsoup4