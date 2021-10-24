.PHONY: clean main index

main: build index
	
build:
	g++ index/src/index.cpp -o index/bin/index

index: 
	./index/bin/index
