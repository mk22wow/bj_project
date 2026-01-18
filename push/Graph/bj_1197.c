#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int V, E;
int usedsize = 0;

typedef struct Node{
    int destination;
    int weight;
    struct Node* next;
}Node;

Node* list[10000];

typedef struct{
    int dest;
    int dist;
}Heap;

Node* createNode(int destination, int weight){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int start, int dest, int wei){
    Node* newNode = createNode(dest, wei);
    newNode->next = list[start];
    list[start] = newNode;
}

void swap(Heap* a, Heap* b){
    Heap temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap* h, int dest, int dist){
    int index = usedsize;
    h[usedsize++] = (Heap){dest, dist};
    int parent_index = (index-1)/2;
    while(index>0 && h[index].dist<h[parent_index].dist){
        swap(&h[index], &h[parent_index]);
        index = parent_index;
        parent_index = (index-1)/2;
    }
}

Heap pop(Heap* h){
    Heap root = h[0];
    h[0] = h[--usedsize];
    int parent_index = 0;
    int leftchild = 1, rightchild = 2;
    int selectchild;
    while(1){
        if(leftchild>=usedsize) break;
        if(rightchild>=usedsize) selectchild = leftchild;
        else if(h[leftchild].dist<h[rightchild].dist) selectchild = leftchild;
        else selectchild = rightchild;

        if(h[parent_index].dist>h[selectchild].dist){
            swap(&h[parent_index], &h[selectchild]);
            parent_index = selectchild;
            leftchild = parent_index*2 +1;
            rightchild = leftchild+1;
        }
        else break;
    }
    return root;
}

void Prim(Heap* h, int s){
    int* key = (int*)malloc(sizeof(int)*V);
    int* pass = (int*)calloc(V, sizeof(int));
    for(int i=0; i<V; i++){
        key[i] = INT_MAX;
    }
    key[s] = 0;
    push(h, s, 0);

    int total = 0;

    while(usedsize>0){
        Heap top = pop(h);
        int top_pos = top.dest;

        if(pass[top_pos]) continue;
        pass[top_pos] = 1;
        
        total += top.dist;
        Node* temp = list[top.dest];
        while(temp!=NULL){
            int temp_pos = temp->destination;
            int temp_weight = temp->weight;
            if(!pass[temp_pos]&& temp_weight<key[temp_pos]){
                key[temp_pos] = temp_weight;
                push(h, temp_pos, key[temp_pos]);
            }
            temp = temp->next;
        }
    }

    int answer = 1;
    for(int i=0; i<V; i++){
        if(!pass[i]){
            answer = 0;
            break;
        }
    }
    
    if(answer){
        printf("%d\n", total);
    }
    else printf("0\n");
    free(key);
    free(pass);
}

int main(void){
    scanf("%d %d", &V, &E);
    memset(list, 0, sizeof(Node*)*V);
    Heap* h = (Heap*)malloc(sizeof(Heap)*(V+E));
    int a, b, c;
    for(int i=0; i<E; i++){
        scanf("%d %d %d", &a, &b, &c);
        addEdge(a-1, b-1, c);
        addEdge(b-1, a-1, c);
    }

    Prim(h, a-1);
    for(int i=0; i<V; i++){
        Node* temp = list[i];
        while(temp!=NULL){
            Node* current = temp->next;
            free(temp);
            temp = current;
        }
    }
    free(h);
    return 0;
}

// int V, E;

// typedef struct{
//     int u;
//     int v;
//     int weight;
// }Edge;

// int parent[10001];

// int Compare(const void* a, const void* b){
//     Edge* pa = (Edge*)a;
//     Edge* pb = (Edge*)b;
//     return pa->weight - pb->weight;
// }

// int Find(int i){
//     if(parent[i] == i){
//         return i;
//     }
//     return parent[i] = Find(parent[i]);
// }

// void unionSets(int i, int j){
//     int root_i = Find(i);
//     int root_j = Find(j);
//     if(root_i != root_j){
//         parent[root_i] = root_j;
//     }
// }

// void Kruskal(Edge* edges){
//     qsort(edges, E, sizeof(Edge), Compare);

//     for(int i=0; i<V; i++){
//         parent[i] = i;
//     }

//     int total = 0;
//     int edge_count = 0;

//     for(int i=0; i<E; i++){
//         if(Find(edges[i].u) != Find(edges[i].v)){
//             unionSets(edges[i].u, edges[i].v);
//             total += edges[i].weight;
//             edge_count++;

//             if(edge_count == V-1) break;
//         }
//     }
//     if(V>0 && edge_count == V-1){
//         printf("%d\n", total);
//     }
//     else printf("0\n");
// }

// int main(void){
//     if(scanf("%d %d", &V, &E) != 2) return 0;

//     Edge* edges = (Edge*)malloc(sizeof(Edge)*E);
//     for(int i=0; i<E; i++){
//         int u, v, w;
//         scanf("%d %d %d", &u, &v, &w);
//         edges[i].u = u-1;
//         edges[i].v = v-1;
//         edges[i].weight = w;
//     }

//     Kruskal(edges);
//     free(edges);
//     return 0;
// }