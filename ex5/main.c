#include <stdlib.h>
#include <stdio.h>

/* PokePCClone libraries */
#include "util.h"
#include "poketype.h"
#include "pokemon.h"
#include "pokebox.h"
#include "pokedex.h"
#include "savemanager.h"
#include "moves.h"
/* End PokePCClone libraries */

#include "pokepc.h"

#define POKEPC_START_SIZE 3

typedef enum {
    OP_MOVE_BOX_RIGHT = 1,
    OP_MOVE_BOX_LEFT = -1,
    OP_ADD_NEW_BOX = 2,
    OP_REMOVE_CURRENT_BOX = -2,
    OP_ADD_PKMN_POS_ZERO = 3,
    OP_ADD_PKMN_INDICATED_POS = 4,
    OP_REMOVE_PKMN_INDICATED_POS = -4,
    OP_PRINT_CURRENT_BOX = 5,
    OP_STOP = 0,
} PokePC_Op;

int main(){
    pokemon_t** pkdex;
    int totalPkmn = 0;

    pkdex = readPkDex(&totalPkmn);

    PokePC *pc = pokePC_init(POKEPC_START_SIZE);

    int op;
    int arg1, arg2;

    do {
        scanf("%d", &op);

        switch(op) {
            case OP_MOVE_BOX_RIGHT:
                pokePC_moveRight(pc);
                break;

            case OP_MOVE_BOX_LEFT:
                pokePC_moveLeft(pc);
                break;

            case OP_ADD_NEW_BOX:
                pokePC_addEmptyBox(pc);
                break;

            case OP_REMOVE_CURRENT_BOX:
                pokePC_removeCurrentBox(pc);
                break;

            case OP_PRINT_CURRENT_BOX:
                pokePC_printCurrentBox(pc);
                break;

            case OP_ADD_PKMN_POS_ZERO:
                scanf("%d", &arg1);
                pokePC_addPkmn(pc, pkdex[arg1], 0);
                break;

            case OP_ADD_PKMN_INDICATED_POS:
                scanf("%d", &arg1);
                scanf("%d", &arg2);
                pokePC_addPkmn(pc, pkdex[arg1], arg2);
                break;

            case OP_REMOVE_PKMN_INDICATED_POS:
                scanf("%d", &arg1);
                pokePC_removePkmnIndicatedPos(pc, arg1);
                break;
        }

    } while (op != OP_STOP);

    pokePC_free(pc);

    for(int i = 0; i < totalPkmn; ++i){
        free(pkdex[i]);
    }
    free(pkdex);
}
