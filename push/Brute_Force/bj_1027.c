#include <stdio.h>
#include <limits.h>
//#include <float.h>
#include <stdlib.h>

int N;
int list[50];
int Max = INT_MIN;

int Function(int a, int b){
    if(abs(a-b) == 1){
        return 1;
    }

    double gradient = (double)(list[b]-list[a])/(double)(b-a);
    int intercept = list[a];
    for(int i=a+1; i<b; i++){
        if((gradient*(i-a)+intercept)<=list[i]) return 0;
    }
    return 1;
}

void Find(int s){
    int temp = 0;
    for(int i=0; i<s; i++){
        temp += Function(i, s);
    }
    for(int i=s+1; i<N; i++){
        temp += Function(s, i);
    }

    Max = Max>temp ? Max:temp;
}

// void Find(int s){
//     int temp = 0;
//     double grad = -DBL_MAX;
//     for(int i=s-1; i>=0; i--){
//         double current = (double)(list[s]-list[i])/(double)(s-i);
//         if(current>grad){
//             grad = current;
//             temp++;
//         }
//     }

//     grad = -DBL_MAX;
//     for(int i=s+1; i<N; i++){
//         double current = (double)(list[i]-list[s])/(double)(i-s);
//         if(current>grad){
//             grad = current;
//             temp++;
//         }
//     }

//     Max = Max>temp ? Max:temp;
// }

int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
    }

    for(int i=0; i<N; i++){
        Find(i);
    }
    printf("%d\n", Max);
    return 0;
}