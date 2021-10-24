.PHONY: clean main index

main: build index
	
build:
	g++ index/src/index.cpp -o index/bin/index.out

index: 
	./index/bin/index.out
