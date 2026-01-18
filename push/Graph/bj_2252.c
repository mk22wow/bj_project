#include <stdio.h>
#include <stdlib.h>

int N, M;

typedef struct Node{
    int destination;
    struct Node* next;
}Node;

typedef struct Graph{
    int Vertices;
    int* degree;
    Node** list;
}Graph;

Node* createNode(int d){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = d;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->Vertices = V;
    G->degree = (int*)calloc(V, sizeof(int));
    G->list = (Node**)calloc(V, sizeof(Node*));
    return G;
}

void addEdge(Graph* G, int s, int e){
    Node* newNode = createNode(e);
    newNode->next = G->list[s];
    G->list[s] = newNode;
    G->degree[e]++;
}

void topologicalSort(Graph* G){
    int v = G->Vertices;
    int* Q = (int*)malloc(sizeof(int)*v);
    int front = 0, rear = 0;
    int* result = (int*)malloc(sizeof(int)*v);
    for(int i=0; i<v; i++){
        if(G->degree[i] == 0){
            Q[rear++] = i;
        }
    }

    int index = 0;
    while(front<rear){
        int temp = Q[front++];
        result[index++] = temp;
       
        Node* current = G->list[temp];
        while(current!=NULL){
            int next_v = current->destination;
            G->degree[next_v]--;
            if(G->degree[next_v] == 0){
                Q[rear++] = next_v;
            }
            current = current->next;
        }
    }

    if(index!=v){
        printf("\n");
    }
    else{
        for(int i=0; i<v; i++){
            printf("%d ", result[i]+1);
        }
    }

    free(Q);
    free(result);
}

int main(void){
    scanf("%d %d", &N, &M);
    Graph* G = createGraph(N);

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(G, a-1, b-1);
    }
    topologicalSort(G);
    
    for(int i=0; i<N; i++){
        Node* temp = G->list[i];
        while(temp){
            Node* current = temp->next;
            free(temp);
            temp = current;
        }
    }
    free(G->degree);
    free(G);
    return 0;
}