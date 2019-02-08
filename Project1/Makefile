G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla -Werror
SRCS = main.cpp
EXEC = proj1

all: compile runSample

compile: $(SRCS)
	$(G++) -o $(EXEC) $(SRCS) 

runSample: $(EXEC) sample.txt.xml
	./$(EXEC) sample.txt.xml

clean:
	rm -rf $(EXEC)

