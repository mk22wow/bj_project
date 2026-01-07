#include <stdio.h>

int main(void){
    int A, T, n;
    scanf("%d", &A);
    if(A<1 || A>2000) return 0;
    scanf("%d", &T);
    if(T<1 || T>10000) return 0;
    scanf("%d", &n);
    if(n!=0 && n!=1) return 0;

    int i=4, count = 0, result = 0;
    while(1){
        count+=i;
        if(T<=count){
            int current = (count-i)*2;
            int temp = T - count + i;
            if(temp<=2){
                if(n==0){
                    current += (temp*2)-1;
                }
                else{
                    current += (temp*2);
                }
            }
            else{
                if(n==0){
                    current += 2 + (temp);
                }
                else{
                    current += i + temp;
                }
            }
            result = (current-1)%A;
            break;
        }
        i++;
    }
    printf("%d\n", result);
    return 0;
}