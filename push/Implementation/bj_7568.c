#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    int weight;
    int height;
    int rank;
    struct Node* next;
}Node;

Node* create_node(int weight, int height){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }

    newNode->weight = weight;
    newNode->height = height;
    newNode->rank = 1;
    newNode->next = NULL;
    return newNode;
}

void insert_node(Node** list_body, int weight, int height){
    Node* newNode = create_node(weight, height);
    
    if((*list_body) == NULL){
        (*list_body) = newNode;
        return;
    }

    Node* temp = (*list_body);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void destroy_node(Node* list_body){
    Node* head = list_body;
    Node* temp = NULL;
    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
    return;
}

void body_rank(Node* list_body, int times){
    Node* currentNode = list_body;
    Node* temp = NULL;
    Node* next = NULL;
    for(int i=0; i<times-1; i++){
        next = currentNode->next;
        while(next!=NULL){
            if(currentNode->height > next->height && currentNode->weight > next->weight){
                next->rank++;
            }
            else if(currentNode->height < next->height && currentNode->weight < next->weight){
                currentNode->rank++;
            }
            next = next->next;
        }
        currentNode = currentNode->next;
    }
}

void print_rank(Node* list_body){
    Node* currentNode = list_body;
    
    while(currentNode!=NULL){
        printf("%d ", currentNode->rank);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(void){
    Node* list_body = NULL;
    int times = 0;
    scanf("%d", &times);

    for(int i=0; i<times; i++){
        int height = 0, weight = 0;
        scanf("%d %d", &height, &weight);
        insert_node(&list_body, height, weight);
    }
    body_rank(list_body, times);
    print_rank(list_body);
    destroy_node(list_body);

    return 0;
}