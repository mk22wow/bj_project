#include <stdio.h>

int A, B;
int result = -1;

int main(void){
    scanf("%d %d", &A, &B);
    int N = B, count = 1;
    while(N>A){
        if(N%2 == 0){
            N/=2;
        }
        else{
            if(N%10 == 1){
                N/=10;
            }
            else break;
        }
        count++;
        if(N == A){
            result = count;
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}