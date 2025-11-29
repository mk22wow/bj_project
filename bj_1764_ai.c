#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 해시 테이블의 버킷을 위한 노드 구조체
typedef struct HashNode {
    char* str;
    struct HashNode* next;
} HashNode;

// 해시 테이블 구조체
typedef struct HashTable {
    HashNode** buckets;
    int size;
    int capacity;
} HashTable;

// 최종 출력용 연결 리스트 노드 구조체
typedef struct Node {
    char* str;
    struct Node* next;
} Node;

// 최종 출력용 연결 리스트 구조체
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// 간단한 해시 함수 (DJB2 알고리즘)
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// 해시 테이블 초기화
HashTable* createHashTable(int capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL) return NULL;
    table->capacity = capacity;
    table->size = 0;
    table->buckets = (HashNode**)calloc(table->capacity, sizeof(HashNode*));
    if (table->buckets == NULL) {
        free(table);
        return NULL;
    }
    return table;
}

// 해시 테이블에 문자열 삽입
void insertHashTable(HashTable* table, char* str) {
    unsigned long index = hash(str) % table->capacity;
    
    HashNode* current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return; // 이미 존재하면 삽입하지 않음
        }
        current = current->next;
    }
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (newNode == NULL) return;
    newNode->str = (char*)malloc(strlen(str) + 1);
    if (newNode->str == NULL) {
        free(newNode);
        return;
    }
    strcpy(newNode->str, str);
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
    table->size++;
}

// 해시 테이블에서 문자열 탐색
int searchHashTable(HashTable* table, char* str) {
    unsigned long index = hash(str) % table->capacity;
    HashNode* current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return 1; // 찾음
        }
        current = current->next;
    }
    return 0; // 못 찾음
}

// 해시 테이블 메모리 해제
void freeHashTable(HashTable* table) {
    if (table == NULL) return;
    for (int i = 0; i < table->capacity; i++) {
        HashNode* current = table->buckets[i];
        while (current != NULL) {
            HashNode* next = current->next;
            free(current->str);
            free(current);
            current = next;
        }
    }
    free(table->buckets);
    free(table);
}

// 최종 출력용 연결 리스트 노드 생성
Node* createNode(char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->str = (char*)malloc(strlen(str) + 1);
    if (newNode->str == NULL) {
        free(newNode);
        return NULL;
    }
    strcpy(newNode->str, str);
    newNode->next = NULL;
    return newNode;
}

// 최종 출력용 연결 리스트에 정렬하여 노드 추가
void addNode_sort(LinkedList* list, char* str) {
    Node* newNode = createNode(str);
    if (newNode == NULL) return; 

    if (list->head == NULL || strcmp(newNode->str, list->head->str) <= 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* pred = list->head;
        while (pred->next != NULL && strcmp(newNode->str, pred->next->str) > 0) {
            pred = pred->next;
        }
        newNode->next = pred->next;
        pred->next = newNode;
    }
    list->size++; 
}

// 최종 출력용 연결 리스트의 모든 노드 해제
void freeNode(LinkedList* list) {
    Node* temp = list->head;
    Node* nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp->str);
        free(temp);
        temp = nextNode;
    }
    list->head = NULL;
    list->size = 0;
}

// 최종 출력용 연결 리스트 출력
void print_unknown(LinkedList* list) {
    Node* temp = list->head;
    printf("%d\n", list->size);
    while (temp != NULL) {
        printf("%s\n", temp->str);
        temp = temp->next;
    }
}

// 문자열 유효성 검사 및 소문자 변환
int checkStr(char* str) {
    if (strlen(str) > 20) return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha((unsigned char)str[i])) return 0;
        str[i] = tolower((unsigned char)str[i]);
    }
    return 1;
}

int main(void) {
    int N, M = 0;
    char str[256];
    
    HashTable* half_unknown_table = createHashTable(100000); 
    if (half_unknown_table == NULL) return 1;

    LinkedList unknown_list = { .head = NULL, .size = 0 };
    
    // N, M 값 입력
    if (scanf("%d %d", &N, &M) != 2) return 1;
    // 입력 버퍼 비우기
    while (getchar() != '\n' && getchar() != EOF);

    // N개의 문자열을 해시 테이블에 삽입
    for (int i = 0; i < N; i++) {
        if (fgets(str, 256, stdin) == NULL) continue;
        str[strcspn(str, "\n")] = '\0';
        if (!checkStr(str)) continue;
        insertHashTable(half_unknown_table, str);
    }
    
    // M개의 문자열을 해시 테이블에서 탐색
    for (int i = 0; i < M; i++) {
        if (fgets(str, 256, stdin) == NULL) continue;
        str[strcspn(str, "\n")] = '\0';
        if (!checkStr(str)) continue;
        
        if (searchHashTable(half_unknown_table, str)) {
            addNode_sort(&unknown_list, str);
        }
    }
    
    print_unknown(&unknown_list);    
    
    freeHashTable(half_unknown_table);
    freeNode(&unknown_list);

    return 0;
}