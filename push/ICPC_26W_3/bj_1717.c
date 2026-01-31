#include <stdio.h>

int n, m;
int parent[1000005];
int rank[1000005] = {0};

int Find(int i){
    if(parent[i] == -1) return i;
    else{
        int x = Find(parent[i]);
        parent[i] = x;
        return x;
    }
}

void Union(int a, int b){
    int r_a = Find(a);
    int r_b = Find(b);
    if(r_a != r_b){
        if(rank[r_a] < rank[r_b]){
            parent[r_a] = r_b;
        }
        else if(rank[r_a] > rank[r_b]){
            parent[r_b] = r_a;
        }
        else{
            parent[r_b] = r_a;
            rank[r_a]++;
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++){
        parent[i] = -1;
    }

    while(m--){
        int q, a, b;
        scanf("%d %d %d", &q, &a, &b);
        if(q == 0){
            Union(a, b);
        }
        else if(q == 1){ 
            if(Find(a) == Find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}