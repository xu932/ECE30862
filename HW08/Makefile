G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla
VALGRIND = valgrind --tool=memcheck --leak-check=full --track-origins=yes
SRCS = Set.cpp main.cpp
EXEC = hw8

parta: compileA run
partb: compileB run

compileA: $(SRCS)
	$(G++) -DPARTA -o $(EXEC) $(SRCS)

compileB: $(SRCS)
	$(G++) -DPARTB -o $(EXEC) $(SRCS)

run: $(EXEC)
	./$(EXEC)

memory: $(EXEC)
	$(VALGRIND) ./$(EXEC)

clean:
	rm -rf $(EXEC)

