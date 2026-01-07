#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100001

typedef struct Node{
    char c;
    struct Node* next;
}Node;

typedef struct{
    int count;
    Node* top;
}Stack;

Node* createNode(char str){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->c = str;
    newNode->next = NULL;
    //printf("%c\n", newNode->c);
    return newNode;
}

void pushNode(Stack* s, char input){
    Node* newNode = createNode(input);
    s->count++;
    newNode->next = s->top;
    s->top = newNode;
}

void popNode(Stack* s){
    Node* temp = s->top;
    s->top = s->top->next;
    s->count--;
    free(temp);
}

int checkNode(Stack* s, char input[]){
    int len = strlen(input);
    int i=0;
    for(i = 0; i<len; i++){
        if(s->top == NULL){
            pushNode(s, input[i]);
            continue;
        }
        //printf("%c", s->top->c);
        if(s->top->c == input[i]){
            popNode(s);
        }
        else{
            pushNode(s, input[i]);
        }
    }
    if(s->top == NULL){
        return 1;
    }
    return 0;
}

void freeNode(Stack* s){
    while(s->top != NULL){
        Node* temp = s->top->next;
        free(s->top);
        s->top = temp;
    }
    free(s);
}


typedef struct Word{
    int result;
    int length;
}Word;

int check_input(Word* good_word, char input[]){
    int len = strlen(input);
    int count_A = 0, count_B = 0;
    if(len<2 || len>100000){
        return 1;
    }
    if(good_word->length + len >1000000){
        return 1;
    }
    for(int i=0; i<len; i++){
        if(input[i]=='A'){
            count_A++;
        }
        else if(input[i]=='B'){
            count_B++;
        }
        else{
            return 1;
        }
    }
    good_word->length += len;
    if(count_A%2!=0 || count_B%2!=0){
        return 2;
    }
    return 0;
}

// void count_good_word(Word* good_word, char input[]){
//     int len = strlen(input);
//     int index_s = -1, index_e = 0;
//     int count = 0;
//     for(int i=0; i<len; i++){
//         if(index_s == -1){
//             index_s = i;
//         }
//         else if(input[index_s] == input[i]){
//             if((i-index_s) % 2==0){
//                 return;
//             }
//             count++;
//             index_s = -1;
//         }
//         else{
//             index_e++;
//         }
//     }
//     if(count>0){
//         good_word->result++;
//     }
// }

int main(void){
    int i = 0, num = 0;
    scanf("%d", &num);
    if(num<1 || num>100){
        printf("wrong input\n");
        return 0;
    }
    Word* good_word = (Word*)malloc(sizeof(Word));
    good_word->result = 0;
    good_word->length = 0;  
    while(i<num){
        char input[MAX_LENGTH];
        scanf("%s", input);
        int check = check_input(good_word, input);
        if(check==1){
            printf("wrong input");
            break;
        }
        Stack* s = (Stack*)malloc(sizeof(Stack));
        s->count = 0;
        s->top = NULL;
        if(check == 0){
            good_word->result += checkNode(s, input);
        }
        freeNode(s);
        i++;
    }
    printf("%d\n", good_word->result);
    free(good_word);
    return 0;
}