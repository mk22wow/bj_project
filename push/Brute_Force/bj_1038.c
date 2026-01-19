#include <stdio.h>
#include <math.h>

int N, count;

long long Find(int n, int i, long long answer){
    if(n == 1){
        count+= i;
        if(count >= N){
            return answer + i - 1 - (count-N);
        }
        return -1;
    }
    for(int j=0; j<=i-1; j++){
        if(n-1<=j){
            long long temp = Find(n-1, j, answer+pow(10, n-1)*j);
            if(temp!=-1) return temp;
        }
    }
    return -1;
}

int main(void){
    scanf("%d", &N);
    if(N<10){
        printf("%d", N);
        return 0;
    }

    int n=2, pass = 0;
    count = 9;
    long long answer;
    while(n<11){
        for(int i=1; i<=9; i++){
            answer = Find(n-1, i, i*pow(10,n-1));
            if(answer != -1){
                printf("%lld\n", answer);
                return 0;
            }
        }
        n++;
    }
    printf("-1\n");
    
    return 0;
}