G++ = g++ -std=c++17 -O3 -Wall -Wno-error=shadow --pedantic -Wvla
GamePlay = GamePlay/Attack.cpp GamePlay/Condition.cpp GamePlay/Trigger.cpp
Utility = Utility/XML_parser.cpp
Objects = Objects/Map.cpp Objects/Container.cpp Objects/Creature.cpp Objects/Item.cpp Objects/Room.cpp

SRCS = main.cpp $(GamePlay) $(Utility) $(Objects)

EXEC = proj1

all: compile runSample

compile: $(SRCS)
	$(G++) -o $(EXEC) $(SRCS) 

runSample: $(EXEC) sample.txt.xml
	./$(EXEC) sample.txt.xml

clean:
	rm -rf $(EXEC)

