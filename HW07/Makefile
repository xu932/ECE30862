G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla
VALGRIND = valgrind --tool=memcheck --leak-check=full --track-origins=yes
SRCS = Alarm.cpp GPS.cpp Map.cpp Observer.cpp Subject.cpp main.cpp
EXEC = hw7

all: compile run

compile: $(SRCS)
	$(G++) -o $(EXEC) $(SRCS) 

run: $(EXEC)
	./$(EXEC)

memory: $(EXEC)
	$(VALGRIND) ./$(EXEC)

clean:
	rm -rf $(EXEC)

