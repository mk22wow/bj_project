#include <stdio.h>
#include <string.h>

#define MAXF 200005

int N, F;
char friend[MAXF][22];
int parent[MAXF];
int size[MAXF];
int HT[MAXF];

unsigned int Hash(char str[]){
    unsigned int hash = 5381;
    int c = 0;
    while(str[c]!='\0'){
        hash = ((hash<<5)+hash) + str[c++];
    }
    return hash%MAXF;
}

int Get(char str[]){
    int hash = Hash(str);
    while(HT[hash] != -1){
        if(strcmp(friend[hash], str) == 0) return hash;
        hash = (hash+1)%MAXF;
    }
    strcpy(friend[hash], str);
    HT[hash] = 1;
    return hash;
}

int Find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = Find(parent[i]);
}

int Union(int a, int b) {
	int root_a = Find(a);
	int root_b = Find(b);
    if(size[root_a]<size[root_b]){
        int temp = root_a;
        root_a = root_b;
        root_b = temp;
    }
    if(root_a != root_b){
        parent[root_b] = root_a; 
        size[root_a] += size[root_b];    
    }
    return size[root_a];
}

int main(void){
    scanf("%d", &N);
    while(N--){
        scanf("%d", &F);
        for(int i=0; i<MAXF; i++){
            parent[i] = i;
            size[i] = 1;
            HT[i] = -1;
        }
        for(int i=0; i<F; i++){
            char temp1[22], temp2[22];
            scanf("%s %s", temp1, temp2);
            int hash1 = Get(temp1);
            int hash2 = Get(temp2);
            int answer = Union(hash1, hash2);
            printf("%d\n", answer);
        }
    }
    return 0;
}
