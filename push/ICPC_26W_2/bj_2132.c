#include <stdio.h>
#include <stdlib.h>

int n;
int fruit[10005];

typedef struct Edge{
    int dest;
    struct Edge* next;
}Edge;

Edge* list[10005];
int sum[10005] = {0};
int Q[10005];
int V[10005] = {0};

void addEdge(int s, int e){
    Edge* temp1 = (Edge*)malloc(sizeof(Edge));
    temp1->dest = e;
    temp1->next = list[s];
    list[s] = temp1;
    Edge* temp2 = (Edge*)malloc(sizeof(Edge));
    temp2->dest = s;
    temp2->next = list[e];
    list[e] = temp2;
}

void Find(int s){
    int front = 0, rear = 0;
    Q[rear++] = s;
    V[s] = 1;
    sum[s] += fruit[s];
    while(front<rear){
        int index = Q[front++];
        Edge* curr = list[index];
        while(curr!=NULL){
            if(V[curr->dest] == 0){
                V[curr->dest] = 1;
                sum[curr->dest] += fruit[curr->dest] + sum[index];
                Q[rear++] = curr->dest;
            }
            curr = curr->next;
        }
    }
}

// void dfs(int s, int parent, int current_sum){
//     current_sum += fruit[s];
//     sum[s] = current_sum;

//     if(current_sum>Max){
//         Max = current_sum;
//         s_index = s;
//     }
//     else if(current_sum == Max && s_index>s){
//         s_index = s;
//     }

//     Edge* curr = list[s];
//     while(curr!=NULL){
//         if(curr->dest!=parent){
//             dfs(curr->dest, s, current_sum);
//         }
//         curr = curr->next;
//     }
// }

int main(void){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &fruit[i]);
    }
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }

    Find(1);
    int Max1 = 0, s_index1 = n+1;
    for(int i=1; i<=n; i++){
        if(sum[i]>Max1){
            Max1 = sum[i];
            s_index1 = i;
        }
        else if(sum[i] == Max1 && i<s_index1){
            s_index1 = i;
        }
    }

    for(int i=0; i<=n; i++){
        sum[i] = 0;
        V[i] = 0;
    }
    Find(s_index1);
    int Max2 = 0, s_index2 = n+1;
    for(int i=1; i<=n; i++){
        if(sum[i]>Max2){
            Max2 = sum[i];
            s_index2 = i;
        }
        else if(sum[i]==Max2 && i<s_index2){
            s_index2 = i;
        }
    }

    s_index2 = s_index1>s_index2 ? s_index2:s_index1;
    printf("%d %d\n", Max2, s_index2);

    for(int i=1; i<=n; i++){
        Edge* curr = list[i];
        while(curr!=NULL){
            Edge* temp = curr->next;
            free(curr);
            curr = temp;
        }
    }
    return 0;
}