G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla -Werror
ASRCS = HW3a/Base.cpp HW3a/Derived.cpp HW3a/main.cpp
BSRCS = HW3b/Dog.cpp HW3b/FlyBehavior.cpp HW3b/NoQuack.cpp HW3b/Rubber.cpp HW3b/DogToy.cpp HW3b/FlyWithWings.cpp HW3b/Quack.cpp HW3b/Squeak.cpp HW3b/Duck.cpp HW3b/Mallard.cpp HW3b/QuackQuack.cpp HW3b/DuckSim.cpp HW3b/NoFly.cpp HW3b/RedHead.cpp

hw3a: compile3A run3A
hw3b: compile3B run3B

compile3A: $(ASRCS)
	$(G++) -o hw3a HW3a/Base.cpp HW3a/Derived.cpp HW3a/main.cpp 

run3A: hw3a
	./hw3a

compile3B: $(BSRCS)
	$(G++) -o hw3b HW3b/Dog.cpp HW3b/FlyBehavior.cpp HW3b/NoQuack.cpp HW3b/Rubber.cpp HW3b/DogToy.cpp HW3b/FlyWithWings.cpp HW3b/Quack.cpp HW3b/Squeak.cpp HW3b/Duck.cpp HW3b/Mallard.cpp HW3b/QuackQuack.cpp HW3b/DuckSim.cpp HW3b/NoFly.cpp HW3b/RedHead.cpp

run3B: hw3b
	./hw3b

clean:
	rm -rf hw3a hw3b 
