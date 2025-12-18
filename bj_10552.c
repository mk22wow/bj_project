#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

/*enum VisitMode{Visited = 1, NotVisited = 0};

typedef struct Vertex{
    int data;
    int Visited;
    struct Edge* List;
}Vertex;

typedef struct Edge{
    struct Edge* Next;
    Vertex* Target;
}Edge;

typedef struct Graph{
    Vertex** Vertices;
    int VerticeCount;
}Graph;

Vertex* createVertex(int data){
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));
    V->data = data;
    V->List = NULL;
    V->Visited = NotVisited;

    return V;
}

Graph* createGraph(int M){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->VerticeCount = M;
    G->Vertices = (Vertex**)malloc(sizeof(Vertex*)*M);
    for(int i=0; i<M; i++){
        Vertex* V = createVertex(i+1);
        G->Vertices[i] = V;
    }
    return G;
}

void DestroyVertex(Vertex* V){
    while(V->List != NULL){
        Edge* E = V->List->Next;
        free(V->List);
        V->List = E;
    }

    free(V);
}

void DestroyGraph(Graph* G){
    int N = G->VerticeCount;
    for(int i=0; i<N; i++){
        DestroyVertex(G->Vertices[i]);
    }
    free(G);
}


Edge* createEdge(Vertex* from, Vertex* target){
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->Target = target;
    E->Next = NULL;

    return E;
}

void addEdge(Vertex* V, Edge* E){
    if(V->List == NULL){
        V->List = E;    
    }
}

Vertex* Find(Vertex* V, int* count){
    V->Visited = Visited;
    Edge* E = V->List;

    if(E != NULL){
        (*count)++;
        return E->Target;
    }
    return NULL;
}

int main(void){
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    if(N<1 || N>MAX || M<1 || M>MAX || P<1 || P>M){
        return 0;
    }
    Graph* G = createGraph(M);
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a<1 || a>M || b<1 || b>M){
            DestroyGraph(G);
            return 0;
        }
        Vertex* from = G->Vertices[b-1];
        Vertex* target = G->Vertices[a-1];
        addEdge(from, createEdge(from, target));
    }

    int count = 0;
    Vertex* S = G->Vertices[P-1];
    while(1){
        S = Find(S, &count);
        if(S == NULL){
            printf("%d\n", count);
            break;
        }
        else if(S->data == P){
            printf("-1\n");
            break;
        }
    }

    DestroyGraph(G);
    return 0;
}*/

int main(void){
    int Graph[MAX] = {0};
    int Visited[MAX] = {0};

    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    if(N<1 || N>MAX || M<1 || M>MAX || P<1 || P>M){
        return 0;
    }
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a<1 || a>M || b<1 || b>M){
            return 0;
        }
        Graph[b] = Graph[b]==0 ? a:Graph[b];
    }

    int count = 0;
    int temp = P;
    while(1){
        Visited[temp] = 1;
        if(Graph[temp] == 0){
            printf("%d\n", count);
            break;
        }
        else{
            temp = Graph[temp];
            count++;
            if(Visited[temp] == 1){
                printf("-1\n");
                break;
            }
        }
    }
    return 0;
}