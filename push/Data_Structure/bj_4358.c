#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SPECIES 10000
#define MAX_SIZE 1000000

unsigned long HashValue(char* str){
    unsigned long hashvalue = 0;
    int len = strlen(str);
    for(int i=0; i<len; i++){
        hashvalue += str[i];
    }
    hashvalue = hashvalue % 10001;
    return hashvalue;
}

typedef struct Node{
    char str[100];
    int count;
    struct Node* next;
}Node;

typedef struct{
    int tablesize;
    int species_count;
    int input_count;
    Node** table;
}HashTable;

int Compare(const void* a,const void* b){
    const Node** pa_ptr = (const Node**) a;
    const Node** pb_ptr = (const Node**) b;

    const Node* pa = *pa_ptr;
    const Node* pb = *pb_ptr;
    return strcmp(pa->str, pb->str);
}


HashTable* CreateHT(){
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->tablesize = 10001;
    HT->input_count = 0;
    HT->species_count = 0;
    HT->table = (Node**)calloc(HT->tablesize, sizeof(Node*));
    return HT;
}

Node* CreateNode(char* input){
    int len = strlen(input);
    if(len>30){
        return NULL;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->count = 1;
    newNode->next = NULL;
    strcpy(newNode->str, input);
    return newNode;
}

void freeHash(HashTable* HT){
    for(int i=0; i<HT->tablesize; i++){
        Node* temp = HT->table[i];
        Node* nextNode;
        while(temp!=NULL){
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
    }
    free(HT->table);
    free(HT);
}

void HashSet(HashTable* HT, char* input, Node** list){
    int hashvalue = HashValue(input);
    HT->input_count++;
    Node* temp = HT->table[hashvalue];
    while(temp!=NULL){
        if(strcmp(temp->str, input) == 0){
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = CreateNode(input);
    newNode->next = HT->table[hashvalue];
    HT->table[hashvalue] = newNode;
    list[HT->species_count++] = newNode;
}

void PrintList(int input_count, int species_count, Node** list){
    double result = 0;
    for(int i=0; i<species_count; i++){
        result = (double)list[i]->count / (double)input_count *1000000;
        result = round(result);
        result /= 10000;
        printf("%s %.4f\n", list[i]->str, result);
    }
}

int main(void){
    char input[500];
    HashTable* HT = CreateHT();
    Node** list = (Node**)calloc(10000,sizeof(Node*));
    while(fgets(input, 200, stdin) != NULL){
        int index = strcspn(input, "\n");
        if(index == 0){
            break;
        }
        input[index] ='\0';
        HashSet(HT, input, list);
        if(HT->input_count>MAX_SIZE || HT->species_count>10000){
            break;
        }
    }
    qsort(list, HT->species_count, sizeof(Node*), Compare);
    PrintList(HT->input_count, HT->species_count, list);
    freeHash(HT);
    free(list);
    return 0;
}