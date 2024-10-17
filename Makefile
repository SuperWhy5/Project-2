COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.out QA.cpp buildResultString.cpp 
	$(COMPILER) $(OPTIONS) main.out QA.cpp buildResultString.cpp -o $(PROGRAM)

clean:
	rm * .out