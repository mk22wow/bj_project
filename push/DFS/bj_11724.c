#include <stdio.h>
#include <stdlib.h>

enum VisitMode {Visited = 1, NotVisited = 0};

typedef struct tagVertex{
    int data;
    int Visited;
    struct tagEdge* AdjacencyList;
}Vertex;

typedef struct tagEdge{
    struct tagEdge* Next;
    Vertex* Target;
}Edge;

typedef struct tagGraph{
    Vertex** Vertices;
    int count;
}Graph;

Graph* CreateGraph(int N){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = (Vertex**)malloc(sizeof(Vertex*)*N);
    graph->count = 0;
    return graph;
}

void DestroyVertex(Vertex* V){
    while(V->AdjacencyList != NULL){
        Edge* Edge = V->AdjacencyList->Next;
        free(V->AdjacencyList);
        V->AdjacencyList = Edge;
    }
    free(V);
}

void DestroyGraph(Graph* G, int N){
    for(int i=0; i<N; i++){
        free(G->Vertices[i]);
    }

    free(G);
}

Vertex* CreateVertex(int data){
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));
    V->data = data;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;

    return V;
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int weight){
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->Target = Target;
    E->Next = NULL;

    return E;
}

void DestroyEdge(Edge* E){
    free(E);
}

void AddVertex(Graph* G, Vertex* V){
    G->Vertices[V->data-1] = V;
}

void AddEdge(Vertex* V, Edge* E){
    E->Next = V->AdjacencyList;
    V->AdjacencyList = E;
}

void DFS(Vertex* V){
    V->Visited = Visited;
    Edge* E = V->AdjacencyList;

    while(E !=NULL){
        if(E->Target->Visited == NotVisited){
            DFS(E->Target);
        }
        E = E->Next;
    }
}

// void DFS_2(Vertex* V, int N){
//     Vertex** stack = (Vertex**)malloc(sizeof(Vertex*)*N);
//     int top = -1;

//     stack[++top] = V;
//     while(top>=0){
//         Vertex* V = stack[top--];
//         if(V->Visited == NotVisited){
//             V->Visited = Visited;
//             Edge* E = V->AdjacencyList;
//             while(E!=NULL){
//                 if(E->Target->Visited == NotVisited){
//                     E->Target->Visited = Visited;
//                     stack[++top] = E->Target;
//                 }
//                 E = E->Next;
//             }
//         }
//     }
//     free(stack);
// }

void BFS(Vertex* V, int N){
    Vertex** Queue = (Vertex**)malloc(sizeof(Vertex*)*N);
    int front =0, rear =0;

    V->Visited = Visited;
    Queue[rear++] = V;

    while(front<rear){
        Vertex* V = Queue[front++];

        Edge* E = V->AdjacencyList;
        while(E!=NULL){
            if(E->Target->Visited == NotVisited){
                E->Target->Visited = Visited;
                Queue[rear++] = E->Target;
            }
            E = E->Next;
        }
    }
    free(Queue);
}

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    Graph* G = CreateGraph(N);
    for(int i=1; i<=N; i++){
        Vertex* V = CreateVertex(i);
        AddVertex(G, V);
    }

    for(int i=0; i<M; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        Vertex* temp_1 = G->Vertices[u-1];
        Vertex* temp_2 = G->Vertices[v-1];
        AddEdge(temp_1, CreateEdge(temp_1,temp_2,0));
        AddEdge(temp_2, CreateEdge(temp_2,temp_1,0));
    }

    for(int i=0; i<N; i++){
        Vertex* V = G->Vertices[i];
        if(V->Visited == NotVisited){
            G->count++;
            DFS_2(V, N);
        }
    }

    printf("%d\n", G->count);
    DestroyGraph(G, N);
    return 0;
}