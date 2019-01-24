G++ = g++ -std=c++17 -g -Wall 
SRCS = Base.cpp D1.cpp D1a.cpp D2.cpp main.cpp

all: compile run 

compile: $(SRCS)
	$(G++) -o hw4 ./*.cpp 

run: hw4
	./hw4

clean:
	rm -rf hw4

