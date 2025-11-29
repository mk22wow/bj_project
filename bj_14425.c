#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

unsigned long HashValue(char* str, int tablesize){
    unsigned long hashvalue = 0;
    for(int i=0; i<strlen(str); i++){
        hashvalue += str[i];
    }

    hashvalue %= tablesize;
    return hashvalue;
}

typedef struct Node{
    char str[501];
    struct Node* next;
}Node;

typedef struct{
    int tablesize;
    int right_input;
    Node** list;
}HashTable;

HashTable* CreateHT(int tablesize){
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->list = (Node**)malloc(sizeof(Node*)*tablesize);
    for(int i=0; i<tablesize; i++){
        HT->list[i] = NULL;
    }
    HT->tablesize = tablesize;
    HT->right_input = 0;
    return HT;
}

Node* CreateNode(char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

void freeNode(HashTable* HT){
    for(int i=0; i<HT->tablesize; i++){
        Node* temp = HT->list[i];
        Node* nextNode;
        while(temp!=NULL){
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    free(HT->list);
    free(HT);
}

void Hash_Set(HashTable* HT, char str[], int number){
    unsigned long index = HashValue(str, HT->tablesize);

    switch (number){
        case 0: 
            Node* newNode = CreateNode(str);
            newNode->next = HT->list[index];
            HT->list[index] = newNode;
            break;
        case 1:
            Node* temp = HT->list[index];
            while(temp!=NULL){
                if(strcmp(str, temp->str) == 0){
                    HT->right_input++;
                    break;
                }
                temp = temp->next;
            }
            break;
    }
}

int CheckInput(char* input){
    int len = strlen(input);
    if(len>500 || len<1){
        return 1;
    }
    for(int i=0; i<len; i++){
        if(!islower(input[i])){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if(num1<1 || num1>10000 || num2<1 || num2>10000){
        printf("wrong input");
        return 0;
    }
    int tablesize = num1>num2 ? num1 : num2;
    HashTable* HT = CreateHT(tablesize); 
    for(int i=0; i<num1; i++){
        char input[1000];
        scanf("%s", input);
        if(CheckInput(input)){
            printf("wrong input");
            break;
        }
        Hash_Set(HT, input, 0);
    }

    for(int i=0; i<num2; i++){
        char input[1000];
        scanf("%s", input);
        if(CheckInput(input)){
            printf("wrong input");
            break;
        }
        Hash_Set(HT, input, 1);
    }

    printf("%d\n", HT->right_input);

    freeNode(HT);
}