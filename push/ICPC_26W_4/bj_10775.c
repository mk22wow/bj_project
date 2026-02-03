#include <stdio.h>

int G, P;
int parent[100005];

int Find(int i){
    if(parent[i] == i) return i;
    return parent[i] = Find(parent[i]);
}

int main(void){
    scanf("%d %d", &G, &P);
    for(int i=1; i<=G; i++){
        parent[i] = i;
    }
    
    int count = 0, pass = 1;
    for(int i=0; i<P; i++){
        int n;
        scanf("%d", &n);
        if(pass == 1){
            int root = Find(n);
            if(root == 0){
                pass = 0;
            }
            else{
                parent[root] = (root-1);
                count++; 
            }
        }
       
    }
    printf("%d\n", count);
}