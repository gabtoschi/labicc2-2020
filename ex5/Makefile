UTIL=moves.c pokebox.c pokedex.c pokemon.c poketype.c savemanager.c spritemanager.c util.c pokepc.c
MAIN=main.c
BINARY=pokemon

all:
	gcc -Wall $(MAIN) $(UTIL) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
