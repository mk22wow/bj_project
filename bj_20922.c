#include <stdio.h>
#include <limits.h>

int N, K;
int value[200000];
int list[100000] = {0};
int count = INT_MIN, Max = INT_MIN;

int main(void){
    scanf("%d %d", &N, &K);
    int current=0;
    int index = 0;
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &value[i]);
        temp = value[i]-1;
        list[temp]++;
        if(list[temp]>count) count = list[temp];
        current++;
        if(count>K){
            int start_index = index;
            while(list[temp]>K){
                list[value[index++]-1]--;
            }
            count = list[temp];
            current -= index-start_index;
        }
        else{
            if(current>Max) Max = current;
        }
    }

    printf("%d\n", Max);
    return 0;
}