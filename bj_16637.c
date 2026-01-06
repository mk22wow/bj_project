#include <stdio.h>
#include <string.h>
#include <limits.h>

char str[20];
int N;
int Max = INT_MIN;

int Calculate(int a, int b, char sign){
    switch(sign){
        case '+':{
            return a+b;
        }
        case '-':{
            return a-b;
        }
        case '*':{
            return a*b;
        }
        default:
            return 0;
    }
}

void Find(int s, int value){
    if(s > N-1){
        Max = Max>value ? Max:value;
        return;
    }
    char sign = (s==0) ? '+':str[s-1];

    if(s+2<N){
        int temp = Calculate(str[s] - '0', str[s+2] - '0', str[s+1]);
        Find(s+4, Calculate(value, temp, sign));
    }
    Find(s+2, Calculate(value, str[s] - '0', sign));
}

int main(void){
    scanf("%d", &N);
    scanf("%s", str);
    
    Find(0, 0);

    printf("%d\n", Max);
    return 0;
}