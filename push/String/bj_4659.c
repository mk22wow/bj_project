#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct strNode {
    char data;
    int vowel;
    int len;
    struct strNode* next;
}Node;

typedef struct LinkedList {
    Node* head;
    int size;
}LinkedList;

int checkVowel(char data);

Node* createNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return NULL;
    }
    int vowel = checkVowel(data);
    newNode->data = data;
    newNode->vowel = vowel;
    newNode->next = NULL;
    return newNode;
}

void addNode(LinkedList* password, char data){
    Node* newNode = createNode(data);
    if((password->head)==NULL){
        (password->head) = newNode;
    }
    else{
        Node* temp = (password->head);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    password->size++;
}

int checkPassword(LinkedList* password){
    Node* temp = password->head;
    int vowel = 0;
    while(temp!=NULL){
        if(temp->vowel == 1){
            vowel = 1;
            break;
        }
        temp=temp->next;
    }
    if(vowel == 0){
        return 0;
    }

    temp = password->head;

    if(password->size>2){
        while(temp->next->next!=NULL){
            if(temp->vowel == temp->next->vowel && temp->next->vowel == temp->next->next->vowel){
               //printf("%c %c %c",temp->data, temp->next->data, temp->next->next->data);
                return 0;
            }
            temp=temp->next;
        }
    }

    temp = password->head;

    if(password->size>1){
        while(temp->next!=NULL){
            if(temp->data == temp->next->data){
                if(temp->data != 'e' && temp->data != 'o'){
                    //printf("2sequence error\n");
                    return 0;
                }
            }
            temp = temp->next;
        }
    }

    return 1;
}

void freeNode(LinkedList* password){
    Node* temp = password->head;
    Node* nextNode;
    while(temp!=NULL){
        nextNode = temp->next;
        free(temp);
        temp=nextNode;
    }
    // password->head = NULL;
    // password->size = 0;
    //printf("free\n");
}

int checkVowel(char data){
    char list[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<sizeof(list)/sizeof(char); i++){
        if(data == list[i]){
            return 1;
        }
    }
    return 0;
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

int checkEnd(char str[]){
    if(!strcmp(str, "end")){
        return 1;
    }
    return 0;
}

// // 최적화된 checkPassword 함수
// int checkPassword(LinkedList* password) {
//     if (password->head == NULL) {
//         return 0; // 빈 비밀번호는 유효하지 않다고 가정
//     }

//     Node* temp = password->head;
//     int hasVowel = 0;
//     int consecutiveVowel = 0;
//     int consecutiveConsonant = 0;
    
//     while (temp != NULL) {
//         // 1. 모음 포함 여부 확인
//         if (temp->vowel == 1) {
//             hasVowel = 1;
//         }

//         // 2. 3개 연속 모음/자음 확인
//         if (temp->vowel == 1) { // 현재 문자가 모음일 경우
//             consecutiveVowel++;
//             consecutiveConsonant = 0;
//         } else { // 현재 문자가 자음일 경우
//             consecutiveConsonant++;
//             consecutiveVowel = 0;
//         }

//         if (consecutiveVowel >= 3 || consecutiveConsonant >= 3) {
//             return 0;
//         }

//         // 3. 같은 글자 연속 확인 (e, o 제외)
//         if (temp->next != NULL) {
//             if (temp->data == temp->next->data) {
//                 if (temp->data != 'e' && temp->data != 'o') {
//                     return 0;
//                 }
//             }
//         }
        
//         temp = temp->next;
//     }

//     return hasVowel;
// }

int main(void){

    char str[256];

    while(1){
    if(fgets(str, 255, stdin) == NULL){
        printf("wrong input1\n");
        continue;
    }
    str[strcspn(str, "\n")] = '\0';
    if(!checkStr(str)){
        printf("wrong input2\n");
        continue;
    }

    if(checkEnd(str)){
        break;
    }

    LinkedList password;
    password.head = NULL;
    password.size = 0;
    for(int i=0; i<strlen(str); i++){
        addNode(&password, str[i]);
    }
    if(checkPassword(&password)){
        printf("<%s> is acceptable.\n", str);
    }
    else{
        printf("<%s> is not acceptable.\n", str);
    }    
    freeNode(&password);
    }
    return 0;
}