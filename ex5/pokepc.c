#include <stdbool.h>

#include "pokepc.h"

#define addOneMod(x, n) (x + 1) % n
#define subOneMod(x, n) (x - 1 + n) % n

typedef struct pokepcnode_t PokePCNode;

struct pokepcnode_t {
    pokemon_t **box;
    PokePCNode *prev;
    PokePCNode *next;
};

struct pokepc_t {
    int size;
    int currentBox;
    int currentPkmn;
    PokePCNode *head;
};

PokePCNode *pokePC_getNodeByIndex(PokePC *pc, int index) {
    PokePCNode *node = pc->head;

    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    return node;
}

void pokePC_freeNode(PokePCNode *node) {
    if (node->box) {
        free(node->box);
    }

    free(node);
}

PokePC *pokePC_init(int startSize) {
    PokePC *pc = malloc(sizeof(PokePC));

    pc->size = 0;
    pc->currentBox = 0;
    pc->currentPkmn = 0;
    pc->head = NULL;

    for (int i = 0; i < startSize; i++){
        pokePC_addEmptyBox(pc);
    }

    return pc;
}

void pokePC_addEmptyBox(PokePC *pc) {
    PokePCNode *newNode = malloc(sizeof(PokePCNode));

    // printBox dá seg fault quando chamado como indica o PDF de exemplo
    // newNode->box = NULL;
    newNode->box = calloc(BOXSIZE, sizeof(pokemon_t));

    if (pc->size == 0) { // empty list
        newNode->prev = newNode;
        newNode->next = newNode;

        pc->head = newNode;
        pc->size++;

        return;
    }

    // non-empty list, find the last
    PokePCNode *lastNode = pokePC_getNodeByIndex(pc, pc->size - 1);

    newNode->prev = lastNode;
    newNode->next = pc->head;

    lastNode->next = newNode;
    pc->head->prev = newNode;

    pc->size++;
}

void pokePC_removeCurrentBox(PokePC *pc) {
    if (pc->size == 1) {
        pokePC_freeNode(pc->head);

        pc->head = NULL;
        pc->size = 0;
        pc->currentBox = 0;

        return;
    }

    PokePCNode *previousNode = pokePC_getNodeByIndex(pc, subOneMod(pc->currentBox, pc->size));
    PokePCNode *currentNode = previousNode->next;
    PokePCNode *nextNode = currentNode->next;

    previousNode->next = nextNode;
    nextNode->prev = previousNode;

    if (currentNode == pc->head) {
        pc->head = nextNode;
    }

    if (pc->currentBox == pc->size - 1) {
        pc->currentBox = 0;
    }

    pokePC_freeNode(currentNode);
    pc->size--;
}

void pokePC_print(PokePC *pc) {
    PokePCNode *currentNode = pc->head;

    printf(">> SIZE: %d\n", pc->size);
    printf(">> CURRENT BOX: %d\n", pc->currentBox);
    printf(">> CURRENT PKMN: %d\n", pc->currentPkmn);

    for (int i = 0; i < pc->size; i++){
        printf("=== BOX %d ===\n", i);

        for (int i = 0; i < BOXSIZE; i++) {
            printf("%d ", !currentNode->box[i] ? -1 : currentNode->box[i]->dexNumber);
        }
        printf("\n");

        currentNode = currentNode->next;
    }
}

void pokePC_printCurrentBox(PokePC *pc) {
    printBox(pokePC_getNodeByIndex(pc, pc->currentBox)->box);
}

void pokePC_free(PokePC *pc) {
    PokePCNode *currentNode = pc->head;
    PokePCNode *nextNode;

    for (int i = 0; i < pc->size; i++) {
        nextNode = currentNode->next;

        pokePC_freeNode(currentNode);

        currentNode = nextNode;
    }

    free(pc);
}

void pokePC_moveLeft(PokePC *pc) {
    pc->currentBox = subOneMod(pc->currentBox, pc->size);
}

void pokePC_moveRight(PokePC *pc) {
    pc->currentBox = addOneMod(pc->currentBox, pc->size);
}

void pokePC_addPkmnCurrentPos(PokePC *pc, pokemon_t *addedPkmn) {
    pokePC_addPkmn(pc, addedPkmn, pc->currentPkmn);
}

void pokePC_addPkmn(PokePC *pc, pokemon_t *addedPkmn, int posInBox) {
    PokePCNode *currentNode = pokePC_getNodeByIndex(pc, pc->currentBox);

    int boxIndex = pc->currentBox;
    int pkmnIndex = posInBox;

    while (boxIndex < pc->size) {
        if (!currentNode->box[pkmnIndex]) {
            currentNode->box[pkmnIndex] = addedPkmn;

            // como a especificação não aponta como deve ser o índice da caixa atual
            // caso a inserção seja feita em outra caixa diferente da atual,
            // segue-se o padrão do índice do pokémon atual e fica, após a inserção
            // como o índice da caixa onde ele foi inserido
            pc->currentBox = boxIndex;
            pc->currentPkmn = pkmnIndex;

            return;
        }

        pkmnIndex++;

        if (pkmnIndex >= BOXSIZE) {
            boxIndex++;
            currentNode = currentNode->next;
            pkmnIndex = 0;
        }
    }

    pokePC_addEmptyBox(pc);

    pc->currentPkmn = 0;
    pc->currentBox = pc->size - 1;
    pc->head->prev->box[pc->currentPkmn] = addedPkmn;
}

void pokePC_removePkmnIndicatedPos(PokePC *pc, int removePos) {
    PokePCNode *currentNode = pokePC_getNodeByIndex(pc, pc->currentBox);

    currentNode->box[removePos] = NULL;
}