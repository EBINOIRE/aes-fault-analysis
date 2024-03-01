TARGET = aes_v3.cpp

.PHONY:all
all: clean build run

.PHONY: build
build: main

.PHONY: run
run: main
	./main

.PHONY: clean
clean: 
	rm -rf main

main: $(TARGET)
	g++-13 $(TARGET) -o main

