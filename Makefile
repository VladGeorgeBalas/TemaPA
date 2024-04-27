CC=gcc
EXEC=lanparty
FILES=main.c
LIBS=./libs

build: compile

all: compile

compile:
	$(CC) $(FILES) -L $(LIBS) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)