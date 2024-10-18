COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp QA.cpp buildResultString.cpp 
	$(COMPILER) $(OPTIONS) main.cpp QA.cpp buildResultString.cpp -o $(PROGRAM)

clean:
	rm * .out