#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge{
    int target;
    struct Edge* next;
}Edge;

Edge* createEdge(int data){
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->target = data;
    E->next = NULL;
    return E;
}

void Find(Edge** list, int i, Edge* E, int** result){
    Edge* temp = E;
    while(temp != NULL){
        int Target = temp->target; 
        if(result[i][Target] == 0){
            result[i][Target] = 1;
            Edge* current = list[Target];
            Find(list, i, current, result);    
        };
        temp = temp->next;
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    if(N<1 || N>100){
        return 0;
    }
    Edge** list = (Edge**)calloc(N,sizeof(Edge*));
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            scanf("%d", &temp);
            if(temp == 1){
                Edge* E = createEdge(j);
                E->next = list[i];
                list[i] = E;
            }
        }
    }

    int** result = (int**)malloc(sizeof(int*)*N);
    for(int i=0; i<N; i++){
        result[i] = (int*)calloc(N, sizeof(int));
    }

    for(int i=0; i<N; i++){
        Find(list, i, list[i], result);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

}

// int main(void){
//     int N;
//     if(scanf("%d", &N) != 1 || N<1 || N >MAX) return 0;
//     int graph[MAX][MAX];
    
//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     for(int k=0; k<N; k++){
//         for(int i=0; i<N; i++){
//             for(int j=0; j<N; j++){
//                 if(graph[i][k] && graph[k][j]){
//                     graph[i][j] = 1;
//                 }
//             }
//         }
//     }

//     for(int i=0; i<N; i++){
//         for(int j=0; j<N; j++){
//             printf("%d ", graph[i][j]);
//         }
//         printf("\n");
//     }
// }
