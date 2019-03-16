G++ = g++ -std=c++17 -g
VALGRIND = valgrind --tool=memcheck --leak-check=full --track-origins=yes
GamePlay = GamePlay/Attack.cpp GamePlay/Condition.cpp 
Objects = Objects/Map.cpp Objects/Container.cpp Objects/Creature.cpp Objects/Item.cpp Objects/Room.cpp Objects/Trigger.cpp

SRCS = main.cpp $(GamePlay) $(Objects)
OBJS = $(SRCS:%.cpp=%.o)

EXEC = proj1

all: compile runSample
memory: compile runValgrind

.c.o:
	$(G++) $(SRCS)

compile: $(SRCS)
	$(G++) -o $(EXEC) $(SRCS) 

runSample: $(EXEC) sample.txt.xml
	./$(EXEC) sample.txt.xml

runValgrind: $(EXEC) sample.txt.xml
	$(VALGRIND) ./$(EXEC) sample.txt.xml

clean:
	rm -rf $(EXEC)
	rm -rf $(OBJS)

