#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u;
    int v;
    int id;
}Edge;

Edge E[200005];
int delete[200005];
int head[100005], to[400005], next[400005], count_E;
int color[100005], q[100005];
int N, M, K, S1, S2;

void add(int u, int v){
    count_E++;
    to[count_E] = v;
    next[count_E] = head[u];
    head[u] = count_E;
}

int check(int mid){
    for(int i=1; i<=N; i++){
        color[i] = -1;
    }
    S1 = 0, S2 = 0;
    for(int i=1; i<=N; i++){
        if(color[i]!=-1) continue;
        int front = 0, rear = 0;
        q[rear++] = i;
        color[i] = 0;
        S1++;
        while(front<rear){
            int curr = q[front++];
            int e = head[curr];
            while(e!=NULL){
                if(color[to[e]] == -1){
                    color[to[e]] = 1 - color[curr];
                    if(color[to[e]] == 0) S1++;
                    else S2++;
                    q[rear++] = to[e];
                }
                else if(color[to[e]] == color[curr]) return 0;
                e = next[e];
            }
        }
    }
    return 1;
}

int main(void){
    if(scanf("%d %d %d", &N, &M, &K) != 3) return 0;
    for(int i=1; i<=M; i++){
        scanf("%d %d", &E[i].u, &E[i].v);
        E[i].id = i;
    }
    for(int i=1; i<=K; i++){
        int t;
        scanf("%d", &t);
        delete[t] = i;
    }

    int low = 0, high = K, ans = -1, result1, result2;
    while(low<=high){
        int mid = (low+high)/2;
        count_E = 0;
        for(int i=1; i<=N; i++){
            head[i] = 0;
        }
        for(int i=1; i<=M; i++){
            if(delete[i]==0 || delete[i]>mid){
                add(E[i].u, E[i].v);
                add(E[i].v, E[i].u);
            }
        }
        if(check(mid)){
            ans = mid;
            result1 = S1<S2 ? S1:S2;
            result2 = S1<S2 ? S2:S1;
            high = mid-1;
        }
        else low = mid+1;
    }

    printf("%d\n", ans);
    if(ans!=-1) printf("%d %d\n", result1, result2);
    return 0;
}