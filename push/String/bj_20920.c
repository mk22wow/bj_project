#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*typedef struct Node{
    char str[50];
    int count;
    int length;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(char str[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    strcpy(newNode->str, str);
    //printf("createNode: %s\n", newNode->str);
    newNode->count=1;
    newNode->length = strlen(str);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char str[]){
    if(root == NULL){
        return createNode(str);
    }
    //printf("root_str: %s\n", str);
    int cmp = strcmp(str, root->str);
    //printf("%d\n", cmp);

    if(cmp==0){
        root->count++;
    }
    else if(cmp<0){
        root->left = insert(root->left, str);
    }
    else{
        root->right = insert(root->right, str);
    }
    return root;
}

void tree_traversal(Node* root, Node** list, int* index){
    if(root!=NULL){
        tree_traversal(root->left, list, index);
        list[*index] = root;
        (*index)++;
        tree_traversal(root->right, list, index);
    }
}

void tree_print(Node* root){
    if(root!=NULL){
        tree_print(root->left);
        printf("tree_print: %s \n", root->str);
        tree_print(root->right);
    }
}

void freeTree(Node* root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}*/

/*int main(void){
    Node* root = NULL;
    Node** list = NULL;
    int index = 0;
    int N = 0, M = 0;
    char str[50];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%49s", str);
        if(!check_word(str, M)){
            //printf("wrong_input");
            continue;
        }
        root = insert(root, str);
    }
    list = (Node**)calloc(N, sizeof(Node*));
    tree_traversal(root, list, &index);
    qsort(list, index, sizeof(Node*), compare_info);
    print_list(list);

    freeTree(root);
    free(list);
}*/

unsigned long create_hash(char* str, int tableSize){
    int i=0;
    unsigned long HashValue = 0;

    for(i=0; str[i]!='\0'; i++){
        HashValue = (HashValue<<3) + str[i]; 
        //HashValue = HashValue % tableSize;
    }

    HashValue = HashValue % tableSize;
    return HashValue;
}

typedef struct tagNode{
    char* str;
    int count;
    int length;
    struct tagNode* next;
}Node;

typedef struct HashTable{
    int tableSize;
    Node** list;
}HashTable;

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
    if(newNode->str == NULL){
        free(newNode);
        return NULL;
    }
    strcpy(newNode->str, str);
    newNode->count = 1;
    newNode->length = strlen(str);
    newNode->next = NULL;
    return newNode;
}

void freeNode(Node* theNode){
    free(theNode->str);
    free(theNode);
}

void Hash_Set(HashTable* HT, Node** result, char* str, int* index){
    unsigned long address = create_hash(str, HT->tableSize);
    Node* temp = HT->list[address];

    while(temp!=NULL){
        if(!strcmp(temp->str, str)){
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    
    Node* newNode = create_Node(str);
    if(newNode == NULL){
        return;
    }
    newNode->next = HT->list[address];
    HT->list[address] = newNode;
    result[*index] = newNode;
    (*index)++;
}

void free_HashTable(HashTable* HT){
    for(int i=0; i<HT->tableSize; i++){
        Node* temp = HT->list[i];
        Node* nextNode;
        while(temp!=NULL){
            nextNode = temp->next;
            free(temp->str);
            free(temp);
            temp = nextNode;
        }
    }
    free(HT->list);
    free(HT);
}

int check_word(char str[], int M){
    size_t len = strlen(str);
    if(len<M){
        return 0;
    }
    for(int i=0; i<len; i++){
        if(!isalpha((unsigned char)str[i])){
            return 0;
        }
        str[i] = tolower((unsigned char)str[i]);
    }
    return 1;
}

void print_list(Node** list){
    int i=0;
    while(list[i]!=NULL){
        printf("%s\n", list[i]->str);
        i++;
    }
}

int compare_info(const void* a, const void* b){
    Node* infoa = *(Node**)a;
    Node* infob = *(Node**)b;

    if(infoa->count!=infob->count){
        return infob->count-infoa->count;
    }

    int lena = infoa->length;
    int lenb = infob->length;

    if(lena!=lenb){
        return lenb-lena;
    }
    return strcmp(infoa->str, infob->str);
}

int main(void){
    HashTable* HT = create_hashtable(1000001);
    int index = 0;
    int N = 0, M = 0;
    char str[50];
    scanf("%d %d", &N, &M);
    Node** list = (Node**)calloc(N, sizeof(Node*));
    for(int i=0; i<N; i++){
        scanf("%49s", str);
        if(!check_word(str, M)){
            //printf("wrong_input");
            continue;
        }
        Hash_Set(HT, list, str, &index);
    }
    
    qsort(list, index, sizeof(Node*), compare_info);
    print_list(list);

    free_HashTable(HT);
    free(list);
}