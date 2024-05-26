CC=gcc

build: compile
all: compile run clean

DATA=./libs/data/data.c
LISTS=./libs/list/list.c ./libs/list/utils.c ./libs/list/stack.c ./libs/list/queue.c
LIBS=$(DATA) $(LISTS)

MAIN_FILES=main.c
MAIN_OUT=main.o
main:
	$(CC) -c -g $(MAIN_FILES) -o $(MAIN_OUT)

TASK1_FILES=./comps/task1/task1.c
TASK1_OUT=task1.o
task1:
	$(CC) -c -g $(TASK1_FILES) -o $(TASK1_OUT)

TASK2_FILES=./comps/task2/task2.c
TASK2_OUT=task2.o
task2:
	$(CC) -c -g $(TASK2_FILES) -o $(TASK2_OUT)

TASK3_FILES=./comps/task3/task3.c
TASK3_OUT=task3.o
task3:
	$(CC) -c -g $(TASK3_FILES) -o $(TASK3_OUT)

TASK4_FILES=./comps/task4/task4.c
TASK4_OUT=task4.o
task4:
	$(CC) -c -g $(TASK4_FILES) -o $(TASK4_OUT)

EXEC=lanparty
FILES=$(MAIN_OUT) $(TASK1_OUT) $(TASK2_OUT) $(TASK3_OUT) $(TASK4_OUT)

compile: main task1 task2 task3 task4
	$(CC) -g $(FILES) $(LIBS) -o $(EXEC)
	rm -f $(FILES)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)

