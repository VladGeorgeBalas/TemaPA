CC=gcc
EXEC=lanparty
FILES=main.c ./libs/data/data.c ./libs/data/data.h ./comps/task1/task1.c

build: compile

all: compile

compile:
	$(CC) $(FILES) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)