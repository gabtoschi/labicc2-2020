#ifndef _POKEPC_H_
#define _POKEPC_H_

#include "pokebox.h"

typedef struct pokepc_t PokePC;

PokePC *pokePC_init(int startSize);
void pokePC_addEmptyBox(PokePC *pc);
void pokePC_print(PokePC *pc);
void pokePC_free(PokePC *pc);
void pokePC_moveLeft(PokePC *pc);
void pokePC_moveRight(PokePC *pc);
void pokePC_removeCurrentBox(PokePC *pc);
void pokePC_printCurrentBox(PokePC *pc);
void pokePC_addPkmn(PokePC *pc, pokemon_t *addedPkmn, int posInBox);
void pokePC_addPkmnCurrentPos(PokePC *pc, pokemon_t *addedPkmn);
void pokePC_removePkmnIndicatedPos(PokePC *pc, int removePos);

#endif