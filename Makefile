CC=gcc

build: compile
all: compile run clean

DATA=./libs/data/data.c
LISTS=./libs/list/list.c ./libs/list/utils.c
LIBS=$(DATA) $(LISTS)

MAIN_FILES=main.c
MAIN_OUT=main.o
main:
	$(CC) -c $(MAIN_FILES) -o $(MAIN_OUT)

TASK1_FILES=./comps/task1/task1.c
TASK1_OUT=task1.o
task1:
	$(CC) -c $(TASK1_FILES) -o $(TASK1_OUT)

TASK2_FILES=./comps/task2/task2.c
TASK2_OUT=task2.o
task2:
	$(CC) -c $(TASK2_FILES) -o $(TASK2_OUT)

EXEC=lanparty
FILES=$(MAIN_OUT) $(TASK1_OUT) $(TASK2_OUT)

compile: main task1 task2
	$(CC) $(FILES) $(LIBS) -o $(EXEC)
	rm -f $(FILES)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)

