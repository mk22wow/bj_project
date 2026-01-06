#include <stdio.h>

int N, M, result = 0;
int list[100000] = {0};

int main(void){
    scanf("%d", &N);
    scanf("%d", &M);
    int temp;
    for(int i=0; i<N; i++){
        scanf("%d", &temp);
        list[temp-1]++;
    }

    for(int i=0; i<=M/2; i++){
        int temp = M-(i+1);
        if(temp>0 && temp<=100000){
            if(i == temp-1){
                while(list[i]/2 != 0){
                    list[i] -= 2;
                    result++;
                }
            }
            else while(list[i]>0 && list[temp-1]>0){
                    list[i]--;
                    list[temp-1]--;
                    result++;
                }
        }
    }
    printf("%d\n", result);
    return 0;
}