#include <stdio.h>

void findLCM(int a, int b){
    unsigned long long LCM = 1, GCD = 0;
    int j = a<b ? a:b;
    for(int i=1; i<=j; i++){
        if(a%i == 0 && b%i == 0){
            GCD = i;
        }
    }
    LCM = (unsigned long long)a*(unsigned long long)b;
    LCM /= GCD; 
    printf("%llu\n", LCM);
}

int main(void){
    int num = 0;
    scanf("%d", &num);
    for(int i=0; i<num; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        findLCM(a,b);
    }
    return 0;
}