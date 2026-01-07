#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    int level;
    char name[17];
    struct Node* next;
}Node;

typedef struct GameNode{
    int max_player;
    int player_count;
    int standard_level;
    Node* players;
    struct GameNode* next;
}GameNode;

Node* createNode(int level, char* name){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->level = level;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertPlayer(GameNode* game, Node* newNode){
    game->player_count++;
    Node* predPlayer = game->players;
    Node* currentPlayer = game->players;
    
    while(currentPlayer != NULL){
        if(predPlayer == currentPlayer){
            if(strcmp(newNode->name, currentPlayer->name)<0){
                newNode->next = currentPlayer;
                game->players = newNode;
                return;
            }
            currentPlayer = currentPlayer->next;
        }
        else{
            if(strcmp(newNode->name, currentPlayer->name)<0){
                newNode->next = currentPlayer;
                predPlayer->next = newNode;
                return;
            }
            currentPlayer = currentPlayer->next;
            predPlayer = predPlayer->next;
        }
    }
    predPlayer->next = newNode;
    return;
}

GameNode* createGameNode(int m){
    GameNode* newNode = (GameNode*)malloc(sizeof(GameNode));
    if(newNode == NULL){
        return NULL;
    }
    newNode->max_player = m;
    newNode->player_count = 0;
    newNode->standard_level = 0;
    newNode->next = NULL;
    newNode->players = NULL;
    return newNode;
}

void insertNode(GameNode* game, int level, char* name){
    Node* newNode = createNode(level, name);
    if(newNode == NULL){
        return;
    }
    if(game->player_count == 0){
        game->players = newNode;
        game->standard_level = newNode->level;
        game->player_count++;
        return;
    }
    GameNode* temp = game;
    while(temp != NULL){
        if(temp->player_count<temp->max_player){
            if(newNode->level>=temp->standard_level-10 && newNode->level<=temp->standard_level+10){
                insertPlayer(temp, newNode);
                return;
            }
        }
        temp = temp->next;
    }
    GameNode* newGameNode = createGameNode(game->max_player);
    temp = game;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newGameNode;
    temp->next->players = newNode;
    temp->next->standard_level = newNode->level;
    temp->next->player_count++;
    return;
}

void print_GameNode(GameNode* game){
    GameNode* temp = game;
    while(temp != NULL){
        if(temp->player_count == temp->max_player){
            printf("Started!\n");
        }
        else{
            printf("Waiting!\n");
        }
        Node* player = temp->players;
        while(player != NULL){
            printf("%d %s\n", player->level, player->name);
            player = player->next;
        }
        temp = temp->next;
    }
}

void free_GameNode(GameNode* game){
    GameNode* temp = game;
    GameNode* nextGameNode;
    while(temp != NULL){
        nextGameNode = temp->next; 
        Node* player = temp->players;
        Node* nextPlayer;
        while(player != NULL){
            nextPlayer = player->next;
            free(player);
            player = nextPlayer;
        }
        free(temp);
        temp = nextGameNode;
    }
}

int check_input(int level, char name[]){
    if(level<1 || level>500){
        return 1;
    }
    if(strlen(name)<=16){
        for(int i=0; i<strlen(name); i++){
            if(name[i]<'a' || name[i]>'z'){
                return 1;
            }
        }
    }
    else{
        return 1;
    }
    return 0;
}

int check_repetition(char list_name[][17], char* name, int times){
    for(int i=0; i<times; i++){
        if(strcmp(list_name[i], name) == 0){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int p = 0, m = 0, times = 0;
    char list_name[300][17] = {};
    scanf("%d %d", &p, &m);
    GameNode* game = createGameNode(m);
    while(times<p){
        int level = 0;
        char name[999];
        int repetition = 0;
        scanf("%d %s", &level, name);
        if(check_input(level, name)){
            printf("wrong input");
            continue;
        }
        if(check_repetition(list_name, name, times)){
            printf("wrong input");
            continue;
        }
        strcpy(list_name[times], name);

        insertNode(game, level, name);
        times++;
    }

    print_GameNode(game);
    free_GameNode(game);
    return 0;

}