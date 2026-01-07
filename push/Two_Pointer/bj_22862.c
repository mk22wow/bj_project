#include <stdio.h>

int N, K;
int list[1000000];
int odd[1000000];
int Max = 0;

int main(void){
    scanf("%d %d", &N, &K);
    int index_s = 0, index_e = 0;
    int count = 0, k = K;
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        if(list[i]%2 == 0){
            count++;
        }
        else{
            odd[index_e++] = i;
            if(k == 0){
                count = i - odd[index_s++] - K;
            }
            else{
                k--;
            }
        }
        if(count>Max) Max = count; 
    }

    printf("%d\n", Max);
    return 0;
}