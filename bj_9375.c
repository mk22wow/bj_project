#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// unsigned long HashValue(char input[], int tablesize){
//     int i=0; 
//     unsigned long hashvalue = 0;

//     for(i=0; input[i]!='\0', i++){
//         hashvalue += input[i];
//     }
//     return hashvalue %tablesize;
// }

typedef struct Node{
    char sort[22];
    int count;
}Node;

void insertNode(Node** table, char input[], int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->count = 1;
    strcpy(newNode->sort, input);
    for(int i=0; i<index; i++){
        if(table[i]!=NULL){
            if(strcmp(table[i]->sort, input) == 0){
                table[i]->count++;
                free(newNode);
                return;
            }
        }
    }
    table[index] = newNode;
}

int resultNode(Node** table, int cloth){
    int result = 1;
    for(int i=0; i<cloth; i++){
        if(table[i] != NULL){
            result *= (table[i]->count+1);
            free(table[i]);
        }
    }
    return result-1;
}


int main(void){
    int num = 0, i = 0;
    if(scanf("%d", &num)!=1 || num<1 || num>100){
        printf("wrong input");
        return 0;
    }
    while(i<num){
        int cloth = 0;
        if(scanf("%d", &cloth)!=1 || cloth<0 || cloth>30){
            printf("wrong input");
            break;
        }
        Node** table = (Node**)calloc(cloth, sizeof(Node*));
        char input_1[22];
        char input_2[22];
        for(int j=0; j<cloth; j++){
            scanf("%s %s", input_1, input_2);
            insertNode(table, input_2, j);
        }
        int result = resultNode(table, cloth);
        printf("%d\n", result);
        free(table);
    }
    return 0;
}