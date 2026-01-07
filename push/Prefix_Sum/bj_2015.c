#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 2000000000
#define TableSize 200003

typedef struct Node{
    long long data;
    int count;
    struct Node* next; 
}Node;

typedef struct{
    int tablesize;
    Node** Table;
}HashTable;

HashTable* createHash(){
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->tablesize = TableSize;
    HT->Table = (Node**)calloc(TableSize, sizeof(Node*));
    return HT;
}

Node* createNode(long long data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void InsertHash(HashTable* HT, long long data){
    long long hashvalue = llabs(data) % HT->tablesize;
    if(HT->Table[hashvalue] != NULL){
        Node* temp = HT->Table[hashvalue];
        while(temp!=NULL){
            if(temp->data == data){
                temp->count++;
                return;
            }
            temp = temp->next;
        }
    }
    Node* newNode = createNode(data);
    newNode->next = HT->Table[hashvalue];
    HT->Table[hashvalue] = newNode;
}

void findSum(HashTable* HT, long long result, long long* count){
    int index = abs(result) % HT->tablesize;
    Node* temp = HT->Table[index];
    while(temp!=NULL){
        if(temp->data == result){
            (*count) += temp->count;
            return;
        }
        temp = temp->next;
    }
}

void freeHT(HashTable* HT){
    for(int i=0; i<HT->tablesize; i++){
        Node* temp = HT->Table[i];
        while(temp!=NULL){
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(HT->Table);
    free(HT);
}

int main(void){
    int N;
    long long K;
    scanf("%d %lld", &N, &K);
    if(N<1 || N>200000){
        return 0;
    }
    if(llabs(K)>MAX){
        return 0;
    }
    long long* list = (long long*)malloc(sizeof(long long)*N);
    HashTable* HT = createHash();
    InsertHash(HT, 0);
    long long count = 0;
    for(int i=0; i<N; i++){
        long long temp = 0;
        scanf("%lld", &temp);
        if(abs(temp)>10000){
            free(list);
            freeHT(HT);
            return 0;
        }
        if(i == 0){
            list[i]=temp;
        }
        else{
            list[i] = list[i-1]+temp;
        }
        long long result = list[i]-K;
        findSum(HT, result, &count);
        InsertHash(HT, list[i]);
    }

    printf("%lld\n", count);
    free(list);
    freeHT(HT);
    return 0;
}