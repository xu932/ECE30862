G++ = g++ -std=c++17 -g -Wall -Wshadow --pedantic -Wvla
ASRCS = HW5a/Base.cpp HW5a/dPriv.cpp HW5a/dProt.cpp HW5a/dPublic.cpp HW5a/main.cpp HW5a/PrivDerived.cpp HW5a/ProtDerived.cpp HW5a/PublicDerived.cpp
BSRCS = HW5b/Faculty.cpp HW5b/main.cpp HW5b/Person.cpp HW5b/Student.cpp
STATIC = HW5b/Faculty.cpp HW5b/mainStaticCast.cpp HW5b/Person.cpp HW5b/Student.cpp
DYNAMIC = HW5b/Faculty.cpp HW5b/mainDynamicCast.cpp HW5b/Person.cpp HW5b/Student.cpp

hw5a: compile5A run5A
hw5b: compile5B run5B
static: compileS runS
dynamic: compileD runD

compile5A: $(ASRCS)
	$(G++) -o hw5a $(ASRCS) 

run5A: hw5a
	./hw5a

compile5B: $(BSRCS)
	$(G++) -o hw5b $(BSRCS)

run5B: hw5b
	./hw5b

compileS: $(STATIC)
	$(G++) -o static $(STATIC)

runS: static
	./static

compileD: $(DYNAMIC)
	$(G++) -o dynamic $(DYNAMIC)

runD: dynamic
	./dynamic

clean:
	rm -rf hw5a hw5b static dynamic

