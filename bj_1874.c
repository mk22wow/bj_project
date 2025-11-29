#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
}Node;

typedef struct{
    int capacity;
    int top;
    int size;
    int char_count;
    char* result;
    Node* Nodes;
}Stack;

void CreateStack(Stack** s, int capacity){
    (*s) = (Stack*)malloc(sizeof(Stack));
    (*s)->Nodes = (Node*)malloc(capacity*sizeof(Node));
    (*s)->capacity = capacity;
    (*s)->top = -1;
    (*s)->result = (char*)malloc(capacity);
    (*s)->size = capacity;
    (*s)->char_count = 0;
}

void DestroyStack(Stack* s){
    free(s->Nodes);
    free(s);
}

void InputResult(Stack* s, char c){
    if(s->char_count>=s->size-1){
        s->result = (char*)realloc(s->result, s->size*2);   
        s->size *= 2;
    }
        s->result[s->char_count++] = c;
        s->result[s->char_count] = '\0';
}

void Push(Stack* s, int data){
    s->top++;
    s->Nodes[s->top].data = data;
    InputResult(s, '+');
}

void Pop(Stack* s){
    s->top--;
    InputResult(s, '-');
}

void PrintResult(Stack* s){
    char* str = s->result;
    int i=0;
    while(str[i]!='\0'){
        printf("%c\n", str[i++]);
    }
}

int main(void){
    int num = 0;
    scanf("%d", &num);
    Stack* s= NULL;
    CreateStack(&s, num);
    int* list = (int*)malloc(sizeof(int)*num);

    for(int i=0; i<num; i++){
        scanf("%d", &list[i]);
    }


    int index = 0;
    for(int i=0; i<num; i++){
        int input = list[i];
        while(index<input){
            Push(s, index+1);
            index++;
        }

        if(s->Nodes[s->top].data == input){
            Pop(s);
        }
        else{
            printf("NO");
            break;
        }
    }

    if(s->top == -1){
        PrintResult(s);
    }

    free(s->Nodes);
    free(s->result);
    free(s);
    free(list);

    return 0;
}