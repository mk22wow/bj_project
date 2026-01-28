#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

int N, S, index_E = 0, count = 0;
int Edge[MAX_N];
int to[MAX_N*2];
int next[MAX_N*2];
int disc[MAX_N];
int esc[MAX_N];
int temp_E[MAX_N];

int Compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

void Preorder(int s, int parent){
    disc[s] = ++count;
    int e = Edge[s];
    while(e != 0){
        if(to[e] != parent){
            Preorder(to[e], s);
        }
        e = next[e];
    }
    esc[s] = ++count;
}

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int s, temp_i = 0;
        scanf("%d", &s);
        while(1){
            int d;
            scanf("%d", &d);
            if(d == -1) break;
            temp_E[temp_i++] = d;
        }
        qsort(temp_E, temp_i, sizeof(int), Compare);
        for(int i=0; i<temp_i; i++){
            index_E++;
            to[index_E] = temp_E[i];
            next[index_E] = Edge[s];
            Edge[s] = index_E;
        }
    }
    scanf("%d", &S);
    Preorder(S, -1);

    for(int i=1; i<=N; i++){
        printf("%d %d %d\n", i, disc[i], esc[i]);
    }
    return 0;
}