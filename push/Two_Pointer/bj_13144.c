#include <stdio.h>

int N;
int list[100000];
int value[100001];
long long result = 0;

int main(void){
    scanf("%d", &N);
    int count = 0, start = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &list[i]);
        if(++value[list[i]]>1){
            while(value[list[i]]>1){
                value[list[start++]]--;
            }
            count = i - start + 1;
            result += count; 
        }
        else{
            result += ++count;
        }
    }

    printf("%lld\n", result);
    return 0;
}



