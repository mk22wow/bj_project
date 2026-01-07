#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int N, temp = 0;
int list[100];
int sign[4];
int Max = INT_MIN;
int Min = INT_MAX;

void Find(int b){
    if(b == N){
        Max = Max>temp ? Max:temp;
        Min = Min<temp ? Min:temp;
        return;
    }

    for(int j=0; j<4; j++){
        if(sign[j]!=0){
            int current = temp;
            if(j == 0){
                temp = temp + list[b];
            }
            else if(j == 1){
                temp = temp - list[b];
            }
            else if(j == 2){
                temp = temp * list[b];
            }
            else if(j == 3){
                if(temp < 0) temp = abs(temp) / list[b] * -1;
                else temp = temp / list[b];
            }
            sign[j]--;
            Find(b+1);
            sign[j]++;
            temp = current;
        }
    }
}


int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }
    for(int i=0; i<4; i++){
        scanf("%d", &sign[i]);
    }
    temp = list[0];
    Find(1);

    printf("%d\n", Max);
    printf("%d\n", Min);
    return 0;
}