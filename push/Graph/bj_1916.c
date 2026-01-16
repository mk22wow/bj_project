#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int N, M;
int usedsize = 0;

typedef struct Node{
    int destination;
    int weight;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
}List;

typedef struct{
    int dest;
    int distance;
}Heap;

Node* createNode(int dest, int wei){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = dest;
    newNode->weight = wei;
    newNode->next = NULL;
    return newNode;
}

void addEdge(List* list, int start, int dest, int wei){
    Node* newNode = createNode(dest, wei);
    newNode->next = list[start].head;
    list[start].head = newNode;
}

void push(Heap* h, int dest, int dist){
    int index = usedsize;
    h[usedsize++] = (Heap){dest, dist};
    int parent = (index-1)/2;
    while(index>0 && h[parent].distance>h[index].distance){
        Heap temp = h[parent];
        h[parent] = h[index];
        h[index] = temp;
        index = parent;
        parent = (index-1)/2;
    }
}

Heap pop(Heap* h){
    Heap root = h[0];
    h[0] = h[--usedsize];
    int parent = 0;
    int leftchild = 1, rightchild = 2;
    while(1){
        int selectchild;
        if(leftchild>=usedsize){
            break;
        }
        if(rightchild>=usedsize){
            selectchild = leftchild;
        }
        else{
            if(h[leftchild].distance<h[rightchild].distance) selectchild = leftchild;
            else selectchild = rightchild;
        }

        if(h[selectchild].distance<h[parent].distance){
            Heap temp = h[parent];
            h[parent] = h[selectchild];
            h[selectchild] = temp;
            parent = selectchild;
            leftchild = parent*2 + 1;
            rightchild = leftchild + 1;
        }
        else break;
    }
    return root;
}

void dijkstra(List* list, int start, int end){
    int* dist = (int*)malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        dist[i] = INT_MAX;
    }
    Heap* h = (Heap*)malloc(sizeof(Heap)*(N+M));
    push(h, start, 0);
    dist[start] = 0;

    while(usedsize>0){
        Heap top = pop(h);
        int current_v = top.dest;
        if(current_v == end) break;
        if(top.distance>dist[current_v]) continue;

        Node* edge = list[current_v].head;
        while(edge!=NULL){
            if(dist[current_v]+edge->weight<dist[edge->destination]){
                dist[edge->destination] = dist[current_v]+edge->weight;
                push(h, edge->destination, dist[edge->destination]);
            }
            edge = edge->next;
        }
    }

    if(dist[end]==INT_MAX){
        printf("-1\n");
    }
    else{
        printf("%d\n", dist[end]);
    }

    free(dist);
    free(h);
}

int main(void){
    scanf("%d %d", &N, &M);
    List* list = (List*)malloc(sizeof(List)*N);
    for(int i=0; i<N; i++){
        list[i].head = NULL;
    }
    for(int i=0; i<M; i++){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        addEdge(list, s-1, e-1, w);
    }

    int s, e;
    scanf("%d %d", &s, &e);
    dijkstra(list, s-1, e-1);
    for(int i=0; i<N; i++){
        Node* temp = list[i].head;
        while(temp!=NULL){
            Node* current = temp->next;
            free(temp);
            temp = current;
        }
    }
    free(list);
    return 0;
}