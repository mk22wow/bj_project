#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*typedef struct Node{
    char* str;
    struct Node* next;
}Node;

typedef struct LinkedList{
    Node* head;
    int size;
}LinkedList;

Node* createNode(char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }

    newNode->str = (char*)malloc((strlen(str)+1)*sizeof(char));
    if(newNode == NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

void addNode(LinkedList* list, char* str){
    Node* newNode = createNode(str);
    if(list->head == NULL){
        list->head = newNode;
    }
    else{
        Node* temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

void print_unknown(LinkedList* list){
    Node* temp = list->head;
    printf("%d\n", list->size);
    while(temp!=NULL){
        printf("%s\n", temp->str);
        temp=temp->next;
    }
}

void addNode_sort(LinkedList* list, char* str){
    Node* newNode = createNode(str);
    if (newNode == NULL) {
        return; 
    }
    
    if (list->head == NULL || strcmp(newNode->str, list->head->str) <= 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    
    else {
        Node* pred = list->head;
        
        while (pred->next != NULL && strcmp(newNode->str, pred->next->str) > 0) {
            pred = pred->next;
        }
        
        newNode->next = pred->next;
        pred->next = newNode;
    }

    list->size++; 
}

void check_unknown(LinkedList* list, LinkedList* unknown, char* str){
    Node* temp = list->head;
    while(temp!=NULL){
        if(!strcmp(temp->str, str)){
            addNode_sort(unknown, str);
        }
        temp = temp->next;
    }
}


void freeNode(LinkedList* list){
    Node* temp = list->head;
    Node* nextNode;
    while(temp!=NULL){
        nextNode = temp->next;
        free(temp->str);
        free(temp);
        temp = nextNode;
    }
    list->head = NULL;
    list->size = 0;
    //printf("free");
}

int checkStr(char* str){
    if(strlen(str)>20){
        return 0;
    }
    while(*str != '\0'){
        if(!isalpha((unsigned char)*str)){
            return 0;
        }
        *str = tolower((unsigned char)*str);
        str++;
    }
    return 1;
}



int main(void){
    int N, M = 0;
    char str[256];
    LinkedList half_unknown = {
        .head = NULL, 
        .size = 0
    };
    LinkedList unknown = {
        .head = NULL, 
        .size = 0
    };
    scanf("%d %d", &N, &M);
    while(getchar() != '\n');

    for(int i=0; i<(N+M); i++){
        fgets(str, 256, stdin);
        // if(fgets(str, 256, stdin) == NULL){
        //     printf("wrong input1");
        //     return 0;
        // }
        str[strcspn(str,"\n")] = '\0';
        // if(!checkStr(str)){
        //     printf("wrong input2\n");
        //     return 0;
        // }
        
        if(i<N){
            addNode(&half_unknown, str);
        }
        else{
            check_unknown(&half_unknown, &unknown, str);
        }


    }
        
    print_unknown(&unknown);    
    freeNode(&half_unknown);
    freeNode(&unknown);

    return 0;
}*/

unsigned long create_hash(char* str, int tableSize){
    int i=0;
    int HashValue = 0;

    for(i=0; str[i]!='\0'; i++){
        HashValue = (HashValue<<3) + str[i]; 
        HashValue = HashValue % tableSize;
    }

    HashValue = HashValue % tableSize;
    return HashValue;
}

typedef struct tagNode{
    char* str;
    struct tagNode* next;
}Node;

typedef struct HashTable{
    int tableSize;
    Node** list;
}HashTable;

typedef struct LinkedList{
    Node* head;
    int size;
}LinkedList;

HashTable* create_hashtable(int tableSize){
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->list = (Node**)calloc(tableSize, sizeof(Node*));
    
    //HT->list = (Node**)malloc(tableSize*sizeof(Node*));
    //memset(HT->list, 0, sizeof(Node*)*tableSize);
    HT->tableSize = tableSize;
    return HT;
}

Node* create_Node(char* str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }

    newNode->str = (char*)malloc((strlen(str)+1)*sizeof(char));
    if(newNode == NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

void freeNode(Node* theNode){
    free(theNode->str);
    free(theNode);
}

void Hash_Set(HashTable* HT, char* str){
    unsigned long address = create_hash(str, HT->tableSize);
    Node* temp = HT->list[address];

    while(temp!=NULL){
        if(!strcmp(temp->str, str)){
            return;
        }
    }
    
    Node* newNode = create_Node(str);
    if(newNode == NULL){
        return;
    }
    newNode->next = HT->list[address];
    HT->list[address] = newNode;
    
}

// int Hash_Find(HashTable* HT, char* str){
//     int address = hash(str, HT->tableSize);
//     Node* temp = HT->list[address];
//     while(temp != NULL){
//         if(!strcmp(temp->str, str)){
//             return 1;
//         }
//         temp = temp->next;
//     }
//     return 0;
// }

void free_HashTable(HashTable* HT){
    for(int i=0; i<HT->tableSize; i++){
        Node* temp = HT->list[i];
        Node* nextNode;
        while(temp!=NULL){
            nextNode = temp->next;
            freeNode(temp);
            temp = nextNode;
        }
    }
    free(HT->list);
    free(HT);
}

void addNode_sort(LinkedList* unknown, char* str){
    Node* newNode = create_Node(str);
    Node* temp = unknown->head;
    if(temp == NULL || strcmp(str, temp->str)<0){
        newNode->next = temp;
        unknown->head = newNode;
    }
    else{
        while(temp->next != NULL && strcmp(temp->next->str, str)<0){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    unknown->size++;
    return;
}

void check_unknown(HashTable* HT, LinkedList* unknown, char* str){
    unsigned long address = create_hash(str, HT->tableSize);
    Node* temp = HT->list[address];
    while(temp != NULL){
        if(!strcmp(temp->str, str)){
            addNode_sort(unknown, str);
            return;
        }
        temp = temp->next;
    }
    return;
}

void print_unknown(LinkedList* list){
    Node* temp = list->head;
    printf("%d\n", list->size);
    while(temp!=NULL){
        printf("%s\n", temp->str);
        temp=temp->next;
    }
}

void free_LinkedList(LinkedList* list){
    Node* temp = list->head;
    Node* nextNode;
    while(temp!=NULL){
        nextNode = temp->next;
        free(temp->str);
        free(temp);
        temp = nextNode;
    }
    list->head = NULL;
    list->size = 0;
    //printf("free");
}


int main(void){
    HashTable* HT = create_hashtable(1000001);
    LinkedList unknown = {.head = NULL, .size = 0};
    int N, M = 0;
    char str[256];

    scanf("%d %d", &N, &M);
    while(getchar() != '\n');

     for(int i=0; i<(N+M); i++){
        fgets(str, 256, stdin);
        // if(fgets(str, 256, stdin) == NULL){
        //     printf("wrong input1");
        //     return 0;
        // }
        str[strcspn(str,"\n")] = '\0';
        // if(!checkStr(str)){
        //     printf("wrong input2\n");
        //     return 0;
        // }
        
        if(i<N){
            Hash_Set(HT, str);
        }
        else{
            check_unknown(HT, &unknown, str);
        }


    }
        
    print_unknown(&unknown);    
    free_HashTable(HT);
    free_LinkedList(&unknown);

    return 0;
}




