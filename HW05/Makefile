G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla -Werror
ASRCS = HW5a/Base.cpp HW5a/dPriv.cpp HW5a/dProt.cpp HW5a/dPublic.cpp HW5a/main.cpp HW5a/PrivDerived.cpp HW5a/ProtDerived.cpp HW5a/PublicDerived.cpp
BSRCS = HW5b/Faculty.cpp HW5b/main.cpp HW5b/Person.cpp HW5b/Student.cpp

hw5a: compile5A run5A
hw5b: compile5B run5B

compile5A: $(ASRCS)
	$(G++) -o hw5a $(ASRCS) 

run5A: hw5a
	./hw5a

compile5B: $(BSRCS)
	$(G++) -o hw5b $(BSRCS)

run5B: hw5b
	./hw5b

clean:
	rm -rf hw5a hw5b 
