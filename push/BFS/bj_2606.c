#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dest;
    struct Node* next;
}Node;

int N, M;
Node* Edge[100];

void Find(int s){
    int* Visited = (int*)calloc(N, sizeof(int));
    int front = 0, rear = 0, count = 0;
    int* Q = (int*)malloc(sizeof(int)*(N+M));
    Q[rear++] = s;
    Visited[s] = 1;
    while(front<rear){
        Node* curr = Edge[Q[front++]];
        while(curr!=NULL){
            if(Visited[curr->dest] == 0){
                Visited[curr->dest] = 1;
                count++;
                Q[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
    printf("%d\n", count);
    free(Visited);
    free(Q);
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Node* temp1 = (Node*)malloc(sizeof(Node));
        temp1->dest = b-1;
        temp1->next = Edge[a-1];
        Edge[a-1] = temp1;
        Node* temp2 = (Node*)malloc(sizeof(Node));
        temp2->dest = a-1;
        temp2->next = Edge[b-1];
        Edge[b-1] = temp2;
    }

    Find(0);
    for(int i=0; i<N; i++){
        Node* temp = Edge[i];
        while(temp!=NULL){
            Node* curr = temp->next;
            free(temp);
            temp = curr;
        }
    }
}