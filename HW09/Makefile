SRCS = Main.java MyList.java IntList.java LongList.java
OBJS = $(SRCS:%.java=%)

all: compile run

compile: $(SRCS)
	javac $(SRCS)

run:
	java $(OBJS)

clean:
	rm -rf *.class

