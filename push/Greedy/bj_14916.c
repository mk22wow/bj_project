#include <stdio.h>
#include <limits.h>

int count;
int result = -1;

void Greedy(int n){
    int count5 = n/5, count2 = 0;
    while(count5>=0){
        count = count5;
        int temp = n-(count5*5);
        if(temp%2 == 0){
            count2 = temp/2;
            count += count2;
            result = count;
            return;
        }
        count5--;
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    Greedy(n);    
    printf("%d\n", result);
 
    return 0;
}