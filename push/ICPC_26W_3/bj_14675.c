#include <stdio.h>

#define MAXN 100005

typedef struct{
    int u;
    int v;
}Edge;

Edge list[MAXN*2];

int N, q, list_i = 0;
int head[MAXN] = {0}, to[MAXN*2], next[MAXN*2], e_index[MAXN*2], count_E = 0;
int disc[MAXN], low[MAXN], Parent[MAXN], Children[MAXN];
int time = -1;
int ans_point[MAXN] = {0}, ans_edge[MAXN] = {0};

void addEdge(int u, int v, int i){
    count_E++;
    to[count_E] = v;
    e_index[count_E] = i;
    next[count_E] = head[u];
    head[u] = count_E;
    list[list_i++] = (Edge){u, v};
}

void Preprocess(int s, int parent){
    disc[s] = low[s] = ++time;
    int children = 0;
    int temp_I = head[s];
    while(temp_I!=0){
        int dest = to[temp_I];
        if(dest != parent){
            if(disc[dest] == -1){
                children++;
                Preprocess(dest, s);
                if(low[s]>low[dest]) low[s] = low[dest];
                if(parent!=-1 && low[dest]>=disc[s]){
                    ans_point[s] = 1;
                }
                if(low[dest]>disc[s]){
                    ans_edge[e_index[temp_I]] = 1;
                }
            }
            else{
                if(low[s]>disc[dest]) low[s] = disc[dest];
            }
        }
        temp_I = next[temp_I];
    }

    if(parent == -1 && children>1) ans_point[s] = 1;
    Parent[s] = parent;
    Children[s] = children;

}

void Find(int Q, int n){
    if(Q == 1){
        if(ans_point[n-1] == 1) printf("yes\n");
        else printf("no\n");
        // if(Parent[n-1] == -1 && Children[n-1]>1){
        //     printf("yes\n");
        // }
        // else if(Parent[n-1] == -1 && Children[n-1]<=1){
        //     printf("no\n");
        // }
        // else if(Parent[n-1]!=-1){
        //     int temp_I = head[n-1];
        //     int pass = 1;
        //     while(temp_I != 0){
        //         int dest = to[temp_I];
        //         if(Parent[dest]==n-1 && low[dest]>=disc[n-1]){
        //             pass = 0;
        //             printf("yes\n");
        //             break;
        //         }
        //         temp_I = next[temp_I];
        //     }
        //     if(pass == 1){
        //         printf("no\n");
        //     }
        // }
    }
    else if(Q == 2){
        if(ans_edge[n] == 1){
            printf("yes\n");
        }
        else printf("no\n");
        // Edge temp = list[(n-1)*2];
        // if(Parent[temp.v]==temp.u && low[temp.v]>disc[temp.u]){
        //     printf("yes\n");
        // }
        // else if(Parent[temp.u]==temp.v && low[temp.u]>disc[temp.v]){
        //     printf("yes\n");
        // }
        // else printf("no\n");
        //printf("yes\n");
    }
}

int main(void){
    scanf("%d", &N);
    for(int i=1; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a-1, b-1, i);
        addEdge(b-1, a-1, i);
    }

    for(int i=0; i<N; i++){
        disc[i] = -1;
    }
    for(int i=0; i<N; i++){
        if(disc[i] == -1){
            Preprocess(i, -1);
        }
    }
    
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        Find(a, b);
    }
    return 0;
}