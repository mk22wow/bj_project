#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    int count;
    Node* top;
    Node* tail;
}Stack;

Node* createNode(int i){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = i;
    newNode->next = NULL;
    return newNode;
}

void initNode(Stack* s, int num){
    s->count = 0;
    s->tail = NULL;
    s->top = NULL;
    int i=0;
    for(i=num; i>0; i--){
        Node* newNode = createNode(i);
        if(s->top == NULL){
            s->top = newNode;
            s->tail = newNode;
        }
        else{
            newNode->next = s->top;
            s->top = newNode;
        }
        s->count++;
    }
    //printf("%d %d\n", s->top->data, s->tail->data);
}

void popNode(Stack* s){
    if(s->top != NULL){
        Node* temp = s->top;
        //printf("%d", temp->data);
        s->top = s->top->next;
        s->count--;
        free(temp);
    }
    if(s->top->next != NULL){
        Node* temp = s->top;
        s->top = s->top->next;
        s->tail->next = temp;
        s->tail = temp;
    }

}

int checkNode(Stack* s){
    int result = 0;
    while(s->count != 1){
        popNode(s);
    }
    result = s->tail->data;
    free(s->tail);
    s->tail = NULL;
    s->top = NULL;
    s->count--;
    return result;
}

int main(void){
    int num = 0, i = 0;
    if(scanf("%d", &num) != 1 || num<1 || num>500000){
        printf("wrong input");   
        return 0;
    }
    Stack s;
    int result = 0;
    initNode(&s, num);
    result = checkNode(&s);
    printf("%d\n", result);
    return 0;
}*/

#define MAX_SIZE 500000

typedef struct{
    int front;
    int rear;
}Queue;

void initQueue(int list[], Queue* q, int N){
    q->front = 1;
    q->rear = N;
    for(int i=1; i<=N; i++){
        list[i] = i;
    }
}

void discard(Queue* q){
    q->front = (q->front +1) % MAX_SIZE;
}

void move_back(Queue* q){
    q->front = (q->front+1) % MAX_SIZE;
    q->rear = (q->rear +1) % MAX_SIZE;
}

int main(void){
    int num = 0, i = 0;
    if(scanf("%d", &num) != 1 || num<1 || num>500000){
        printf("wrong input");   
        return 0;
    }
    Queue q;
    int list[MAX_SIZE];
    initQueue(list, &q, num);
    while(q.front != q.rear){
        discard(&q);
        int num = list[q.front];
        move_back(&q);
        list[q.rear] = num;
    }
    printf("%d\n", list[q.front]);
    return 0;
}
