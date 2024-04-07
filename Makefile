CC=gcc
EXEC=lanParty
FILES=main.c

build: compile

compile:
	$(CC) $(FILES) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)