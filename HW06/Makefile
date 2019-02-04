G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla
ASRCS = HW6a/Base.cpp HW6a/D.cpp HW6a/main.cpp 
BSRCS = HW6b/Base.cpp HW6b/Derived.cpp HW6b/main.cpp 

hw6a: compile6A run6A
hw6b: compile6B run6B

compile6A: $(ASRCS)
	$(G++) -o hw6a $(ASRCS) 

run6A: hw6a
	./hw6a

compile6B: $(BSRCS)
	$(G++) -o hw6b $(BSRCS)

run6B: hw6b
	./hw6b

clean:
	rm -rf hw6a hw6b static dynamic

