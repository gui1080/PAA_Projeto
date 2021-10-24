.PHONY: all build index install clean

all: build run

index/bin: 
	mkdir index/bin || true
	
build:
	make -C index

run: 
	./index/bin/index.out

clean:
	make -C index clean

install:
	sudo pip install scrapy beautifulsoup4