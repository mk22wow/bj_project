#include <stdio.h>

int N, X;
int list[250000];

int main(void){
    scanf("%d %d", &N, &X);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    int Max = 0, count = 1;
    for(int i=0; i<X; i++){
        Max += list[i];
    }
    int temp = Max;
    for(int i=X; i<N; i++){
        temp = temp - list[i-X] + list[i];
        if(temp>Max){
            Max = temp;
            count = 1;
        }
        else if(temp == Max){
            count++;
        }
    }

    if(Max == 0){
        printf("SAD\n");
    }
    else printf("%d\n%d", Max, count);
    return 0;
}