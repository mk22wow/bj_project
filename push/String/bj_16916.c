#include <stdio.h>
#include <string.h>

#define HASH 1000003
#define BASE 256

int main(void){
    char a[1000001];
    char b[1000001];
    scanf("%s %s", a, b);
    int len_a = strlen(a);
    int len_b = strlen(b);
   
    long long hash_b = 0;
    long long hash_a = 0;
    long long h = 1;

    for(int i=0; i<len_b-1; i++){
        h = (h*BASE)%HASH;
    }

    for(int i=0; i<len_b; i++){
        hash_b = (hash_b*BASE+b[i])%HASH;
        hash_a = (hash_a*BASE+a[i])%HASH;
    }

    int pass = 0;
    for(int i=0; i<=len_a-len_b; i++){
        if(hash_a == hash_b){
            int match = 1;
            for(int j=0; j<len_b; j++){
                if(a[i+j] != b[j]){
                    match = 0;
                    break;
                }
            }
            if(match){
                pass = 1;
                break;
            }
        }
        if(i<len_a-len_b){
            hash_a = (BASE*(hash_a-a[i]*h) + a[i+len_b])%HASH;
            if(hash_a<0) hash_a +=HASH;
        }
    }

    printf("%d\n", pass);
}