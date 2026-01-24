#include <stdio.h>

long long list[101] = {0};

int main(void){
    int N;
    scanf("%d", &N);

    for(int i=1; i<=6; i++){
        list[i] = i;
    }
    if(N<=6){
        printf("%d\n", N);
        return 0;
    }
    
    for(int i=7; i<=N; i++){
        list[i] = list[i-1]+1;
        for(int j=2; j<5; j++){
            long long temp = list[i-j-1]*j;
            if(temp>list[i]) list[i] = temp;
        }
    }
    printf("%lld\n", list[N]);
    return 0;

}
 
//  1 2 3 a c v(6) v(9) a c v(18) / v(27) a c v(54) v(81) a c v(162) v(243) v(324)

//  1 2 3 4 a c v(8) v(12) v(16) a / c v(32) v(48) v(64)