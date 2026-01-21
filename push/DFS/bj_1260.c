#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, V;
int top = 0;

typedef struct Node{
    int destination;
    struct Node* next;
}Node;

Node* list[1001];
 
Node* createNode(int d){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = d;
    newNode->next = NULL;
    return newNode;
}

void DFS(int* result, int* Visited, int s){
    Node* temp = list[s];
    Visited[s] = 1;
    result[top++] = s;
    while(temp!=NULL){
        if(Visited[temp->destination] == 0){
            DFS(result, Visited, temp->destination);
        }
        temp = temp->next;
    }
}

void BFS(int* result, int* Visited, int s){
    Node** Edge = (Node**)malloc(sizeof(Node*)*(N*N+M));
    int* Q = (int*)malloc(sizeof(int)*(N+1));
    int front = 0, rear = 0;
    Q[rear++] = s;
    //Edge[rear++] = list[s];
    Visited[s] = 1;
    while(front<rear){
        int curr = Q[front++];
        result[top++] = curr;
        Node* temp = list[curr];
        while(temp!=NULL){
            if(Visited[temp->destination] == 0){
                Visited[temp->destination] = 1;
                Q[rear++] = temp->destination;
            }
            temp = temp->next;
        }
    }
    // while(front<rear){
    //     Node* temp = Edge[front++];
    //     while(temp!=NULL){
    //         if(Visited[temp->destination] == 0){
    //             result[top++] = temp->destination;
    //             Visited[temp->destination] = 1;
    //             Edge[rear++] = list[temp->destination];
    //         }
    //         temp = temp->next;
    //     }
    // }
    free(Q);
    //free(Edge);
}

int main(void){
    int count[1000];
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Node* temp1 = createNode(a-1);
        Node* temp2 = createNode(b-1);
        if(list[a-1] == NULL || (b-1)<list[a-1]->destination){
            temp2->next = list[a-1];
            list[a-1] = temp2;
        }
        else{
            Node* temp = list[a-1];
            while(temp->next!=NULL && temp2->destination>temp->next->destination){
                temp = temp->next;
            }
            temp2->next = temp->next;
            temp->next = temp2;
        }

        if(list[b-1] == NULL || (a-1)<list[b-1]->destination){
            temp1->next = list[b-1];
            list[b-1] = temp1;
        }
        else{
            Node* temp = list[b-1];
            while(temp->next!=NULL && temp1->destination>temp->next->destination){
                temp = temp->next;
            }
            temp1->next = temp->next;
            temp->next = temp1;
        }
    }
    int* result = (int*)malloc(sizeof(int)*N);
    int* Visited = (int*)calloc(N, sizeof(int));   
    DFS(result, Visited, V-1);
    for(int i=0; i<top; i++){
        printf("%d ", result[i]+1);
    }
    printf("\n");
    top = 0;
    memset(result, 0, sizeof(int)*N);
    memset(Visited, 0, sizeof(int)*N);
    BFS(result, Visited, V-1);
    for(int i=0; i<top; i++){
        printf("%d ", result[i]+1);
    }
    free(result);
    free(Visited);
    for(int i=0; i<N; i++){
        Node* curr = list[i];
        while(curr!=NULL){
            Node* temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
    return 0;
}