#include <stdio.h>
#include <string.h>

int N, K, Max = 0;
int must[5] = {'a'-'a', 'c'-'a', 'i'-'a', 't'-'a', 'n'-'a'}; 
int list[50] = {0};
int letter[26] = {0};

void Find(int a, int count, int mask){
    if(count == K){
        int temp = 0;
        for(int i=0; i<N; i++){
            if((mask & list[i]) == list[i]){
                temp++;
            }
        }
        if(temp>Max) Max = temp;
        return;
    }

    if(a>26) return;

    if(mask&(1<<a)){
        Find(a+1, count, mask);
    }
    else{
        Find(a+1, count+1, mask|(1<<a));
        Find(a+1, count, mask);
    }
}

int main(void){
    scanf("%d %d", &N, &K);
    if(N<1 || N>50 || K<0 || K>26) return 0;
    for(int i=0; i<N; i++){
        char str[16];
        scanf("%s", str);

        for(int j=0; str[j]; j++){
            list[i] |= (1 << (str[j]-'a'));
        }
    }

    int mask = 0;
    for(int i=0; i<5; i++){
        mask |= (1<<must[i]);
    }
    Find(0, 5, mask);
    printf("%d\n", Max);
}