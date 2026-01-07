#include <stdio.h>

int N, d, k, c;
int value[3000] = {0};
int list[30000];
int Max = 0;

int main(void){
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        //value[list[i]-1]++;
    }

    int count = 0;
    for(int i=0; i<N+k-1; i++){
        int temp = list[i%N] - 1;
        if(++value[temp] == 1) count++;
        if(i>=k-1){
            if(count>=Max){
                Max = count;
                if(value[c-1] == 0){
                    Max++;
                }
            }
            if(--value[list[i-k+1] - 1] == 0) count--;
        }
    }
    
    printf("%d\n", Max);
    return 0;
}