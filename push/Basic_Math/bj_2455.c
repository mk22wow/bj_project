#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data){
    Node* newNode = createNode(data);
    if((*head)==NULL){
        (*head) = newNode;
        return;
    }
    Node* temp = (*head);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void freeNode(Node** head){
    Node* temp = (*head);
    Node* nextNode;
    while(temp!=NULL){
        nextNode = temp->next;
        free(temp);
        temp=nextNode;
    }
    *head = NULL;
    //printf("free");
}

void findMax(Node** head){
    Node* temp = (*head);
    int max = temp->data;
    temp = temp->next;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }    
        temp = temp->next;
    }
    //printf("max : %d\n", max);
    printf("%d\n", max);
}

int main(void) {
    int geton, getoff, total = 0;
    Node* head_total = NULL;
    addNode(&head_total, 0);

    for(int i=0; i<4; i++){
        //printf("getoff, geton : ");
        scanf("%d %d", &getoff, &geton);
        total = total - getoff + geton;
        //printf("%d \n", total);
        addNode(&head_total, total);
    }
   
    findMax(&head_total);
    freeNode(&head_total);
    return 0;
}