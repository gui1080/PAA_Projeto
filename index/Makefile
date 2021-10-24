CPP      = g++
SRCS     = $(shell find src -name *.cpp)
OBJ      = $(addprefix obj/,$(SRCS:%.cpp=%.o))
DIR      = $(addprefix obj/,$(shell find src/ -type d))
BIN      = bin/index.out
RM       = rm -rf

.PHONY: all all-before all-after run clean

all: all-before $(BIN) all-after

all-before:
	mkdir -p obj $(DIR)
	mkdir -p bin

all-after:
	cd ..

$(BIN): $(OBJ)
	$(CPP) $(OBJ) -o $(BIN)

obj/%.o: %.cpp
	$(CPP) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BIN) obj bin
