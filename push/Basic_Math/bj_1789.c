#include <stdio.h>
#include <limits.h>

int main(void){
    long long S;
    scanf("%lld", &S);

    long long i = 1;
    // while(1){
    //     long long n = i*(i+1)/2;
    //     if(n == S){
    //         printf("%lld\n", i);
    //         break;
    //     }
    //     else if(n>S){
    //         printf("%lld\n", i-1);
    //         break;
    //     }
    //     i++;
    // }

    long long low = 1, high = S;
    long long ans;
    while(low<=high){
        long long mid = low + (high-low)/2;
        long long temp = mid*(mid+1)/2;

        if(temp<=S){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    printf("%lld", ans);
    return 0;
}